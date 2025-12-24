from flask import Flask, render_template, request
import subprocess, json

app = Flask(__name__)

# Page 1: Start Simulation
@app.route("/")
def start():
    return render_template("start.html")

# Page 2: Input Page
@app.route("/input")
def input_page():
    return render_template("input.html")

# Page 3: Optimize & Show Result
@app.route("/optimize", methods=["POST"])
def optimize():
    lane0 = request.form["lane0"]
    lane1 = request.form["lane1"]
    lane2 = request.form["lane2"]
    lane3 = request.form["lane3"]
    emergency_lane = request.form["emergency_lane"]

    # Call C program
    result = subprocess.check_output(
        ["../c_logic/traffic.exe", lane0, lane1, lane2, lane3, emergency_lane]
    )

    data = json.loads(result)

    return render_template(
        "result.html",
        green_lane=data["green_lane"],
        reason=data["reason"],
        green_time=data["green_time"]
    )

if __name__ == "__main__":
    app.run(debug=True)


