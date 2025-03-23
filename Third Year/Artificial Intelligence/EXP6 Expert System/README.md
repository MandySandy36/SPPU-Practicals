# Employee Performance Evaluation Expert System

This project is an **Expert System** designed to evaluate employee performance based on key metrics such as task completion, attendance, teamwork, and feedback. The system uses a rule-based approach to calculate a weighted score and classify performance into categories like "Excellent," "Good," "Average," or "Needs Improvement."

---

## Features

- **Rule-Based Evaluation**: Evaluates employee performance using predefined rules and weighted scoring.
- **Web Interface**: A user-friendly web interface built with **Flask** and **Bootstrap**.
- **Scalable Logic**: Teamwork and feedback scores are scaled to a 0-100 range for consistency.
- **Input Validation**: Ensures inputs are within valid ranges (e.g., task completion and attendance between 0-100, teamwork and feedback between 1-5).
- **Responsive Design**: The interface is mobile-friendly and works on all screen sizes.

---

## Technologies Used

- **Python**: Core logic and backend.
- **Flask**: Web framework for building the application.
- **Bootstrap**: Front-end styling for a clean and responsive interface.
- **HTML/CSS**: For structuring and styling the web pages.

---

## Installation and Setup

Follow these steps to set up and run the project on your local machine.

### Prerequisites

- Python 3.x
- pip (Python package manager)

### Steps

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/employee-performance-evaluation.git
   cd employee-performance-evaluation
   ```

2. **Create a Virtual Environment (Optional but recommended)**:
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
   ```

3. **Install Dependencies**:
   ```bash
   pip install -r requirements.txt
   ```
4. **Run the Application**:
   ```bash
   python app.py
   ```
5. **Access the Application**:
   Open your browser and go to http://127.0.0.1:5000/.

## Usage

1. **Input Employee Data**:
   - Enter the following details for the employee:
     - **Task Completion (%)**: Percentage of tasks completed (0-100).
     - **Attendance (%)**: Percentage of attendance (0-100).
     - **Teamwork (1-5)**: Teamwork score on a scale of 1 to 5.
     - **Feedback Score (1-5)**: Feedback score on a scale of 1 to 5.

2. **Evaluate Performance**:
   - Click the **Evaluate** button to see the performance result.

3. **View Results**:
   - The system will display the performance rating:
     - **Excellent**
     - **Good**
     - **Average**
     - **Needs Improvement**

---

## Project Structure

employee-performance-evaluation/

├── app.py                  
├── expert_system.py       
├── templates/── index.html         
├── static/── styles.css          
├── requirements.txt        
└── README.md               


---

## Logic Overview

The evaluation logic is implemented in `expert_system.py`. It calculates a weighted score based on the following parameters:

- **Task Completion (40%)**
- **Attendance (20%)**
- **Teamwork (20%)**: Scaled from 1-5 to 0-100.
- **Feedback (20%)**: Scaled from 1-5 to 0-100.

The total score is classified into performance categories:

| Total Score | Performance Rating   |
|-------------|----------------------|
| ≥ 90        | Excellent            |
| ≥ 75        | Good                 |
| ≥ 50        | Average              |
| < 50        | Needs Improvement    |

---

## Example Test Cases

Here are some example inputs and their corresponding outputs:

| Task Completion | Attendance | Teamwork | Feedback | Performance Rating   |
|-----------------|------------|----------|----------|----------------------|
| 92              | 97         | 4        | 5        | Excellent            |
| 80              | 90         | 3        | 3        | Good                 |
| 60              | 75         | 2        | 2        | Average              |
| 40              | 60         | 1        | 1        | Needs Improvement    |
| 100             | 100        | 5        | 5        | Excellent            |

---

## Contributing

Contributions are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Push your branch and submit a pull request.

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **Flask**: For providing a lightweight and flexible web framework.
- **Bootstrap**: For making it easy to create a responsive and visually appealing interface.
- **Python**: For being an awesome programming language.

---

## Contact

For questions or feedback, feel free to reach out:

- **Email**: mehatabsanadi94@gmail.com
- **GitHub**: https://github.com/MandySandy36

---

Enjoy using the **Employee Performance Evaluation Expert System**! 🚀