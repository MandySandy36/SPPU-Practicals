from flask import Flask, request, render_template
from expert_system import evaluate_performance

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        try:
            task_completion = int(request.form["task"])
            attendance = int(request.form["attendance"])
            teamwork = int(request.form["teamwork"])
            feedback = int(request.form["feedback"])

            # Validate input ranges
            if not (0 <= task_completion <= 100):
                return render_template("index.html", error="Task completion must be between 0 and 100.")
            if not (0 <= attendance <= 100):
                return render_template("index.html", error="Attendance must be between 0 and 100.")
            if not (1 <= teamwork <= 5):
                return render_template("index.html", error="Teamwork score must be between 1 and 5.")
            if not (1 <= feedback <= 5):
                return render_template("index.html", error="Feedback score must be between 1 and 5.")

            result = evaluate_performance(task_completion, attendance, teamwork, feedback)
            return render_template("index.html", result=result)

        except ValueError:
            return render_template("index.html", error="Invalid input! Please enter numbers.")

    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True)
