def evaluate_performance(task_completion, attendance, teamwork, feedback):
    """
    Evaluates employee performance based on weighted scores for task completion, attendance, teamwork, and feedback.

    Args:
        task_completion (int): Percentage of tasks completed (0-100).
        attendance (int): Percentage of attendance (0-100).
        teamwork (int): Teamwork score (1-5).
        feedback (int): Feedback score (1-5).

    Returns:
        str: Performance rating ("Excellent", "Good", "Average", or "Needs Improvement").
    """
    if not (0 <= task_completion <= 100):
        raise ValueError("Task completion must be between 0 and 100.")
    if not (0 <= attendance <= 100):
        raise ValueError("Attendance must be between 0 and 100.")
    if not (1 <= teamwork <= 5):
        raise ValueError("Teamwork must be between 1 and 5.")
    if not (1 <= feedback <= 5):
        raise ValueError("Feedback must be between 1 and 5.")

    teamwork_scaled = teamwork * 20
    feedback_scaled = feedback * 20
    total_score = (task_completion * 0.4) + (attendance * 0.2) + (teamwork_scaled * 0.2) + (feedback_scaled * 0.2)

    if total_score >= 90:
        return "Excellent"
    elif total_score >= 75:
        return "Good"
    elif total_score >= 50:
        return "Average"
    else:
        return "Needs Improvement"
    
    # Example Test Cases
if __name__ == "__main__":
    print(evaluate_performance(92, 97, 4, 5))  # Output: Excellent
    print(evaluate_performance(80, 90, 3, 3))  # Output: Good
    print(evaluate_performance(60, 75, 2, 2))  # Output: Average
    print(evaluate_performance(40, 60, 1, 1))  # Output: Needs Improvement
    print(evaluate_performance(100, 100, 5, 5))  # Output: Excellent