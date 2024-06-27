#include <iostream>
#include <string>
#include <vector>  // Include vector header

using namespace std;

// Abstract base class called exam
class Exam {
public:
    int examID;
    string subject;
    int duration; // Duration in minutes

    // Constructor to initialize common attributes
    Exam(int id, const string& subj, int dur) : examID(id), subject(subj), duration(dur) {
        if (dur <= 0) {
            cout<< "InvalidExamDurationException";
        }
    }

    // Pure virtual function to grade the exam
    virtual double gradeExam() = 0;

    // Virtual destructor
    virtual ~Exam() {}

    // Function to display exam details
    virtual void display() const {
        cout << "Exam ID: " << examID << ", Subject: " << subject << ", Duration: " << duration << " minutes" << endl;
    }

    // Custom exception class for invalid exam duration
    class InvalidExamDurationException : public runtime_error {
    public:
        InvalidExamDurationException() : runtime_error("Invalid exam duration!") {}
    };
};

// Derived class for multiple-choice exams
class MultipleChoiceExam : public Exam {
public:
    vector<string> questions;
    vector<string> correctAnswers;

    // Constructor to initialize specific attributes and base class attributes
    MultipleChoiceExam(int id, const string& subj, int dur, const vector<string>& ques, const vector<string>& answers)
        : Exam(id, subj, dur), questions(ques), correctAnswers(answers) {
        if (ques.size() != answers.size()) {
            cout << "GradingErrorException";
        }
    }

    // Function to grade the exam 
    double gradeExam() override {
        int correct = 0;
        for (size_t i = 0; i < questions.size(); ++i) {
            // Simulate grading by comparing with a predefined correct answer
            if (questions[i] == correctAnswers[i]) {
                ++correct;
            }
        }

        return (correct / static_cast<double>(questions.size())) * 100;
    }

    // Destructor
    ~MultipleChoiceExam() {}

    // Function to display exam details
    void display() const override {
        Exam::display();
        cout << "Number of questions: " << questions.size() << endl;
    }

    // Custom exception class for grading errors
    class GradingErrorException : public runtime_error {
    public:
        GradingErrorException() : runtime_error("Questions and answers were mismatched causing grading errors!") {}
    };
};

// Derived class for essay exams
class EssayExam : public Exam {
public:
    string topic;

    // Constructor to initialize specific attributes and base class attributes
    EssayExam(int id, const string& subj, int dur, const string& top)
        : Exam(id, subj, dur), topic(top) {}

    // Function to grade the exam
    double gradeExam() override {
        double score;
        cout << "Enter the score for the essay on topic \"" << topic << "\": ";
        cin >> score;
        if (score < 0 || score > 100) {
            throw GradingErrorException();
        }
        return score;
    }

    // Destructor
    ~EssayExam() {}

    // Function to display exam details
    void display() const override {
        Exam::display();
        cout << "Essay topic: " << topic << endl;
    }

    // Create exception class for grading errors
    class GradingErrorException : public runtime_error {
    public:
        GradingErrorException() : runtime_error("Invalid score entered for essay exam!") {}
    };
};

int main() {
    try {
        // Examples of MultipleChoiceExam and EssayExam
        vector<string> mcQuestions = {"Q1", "Q2", "Q3"};
        vector<string> mcAnswers = {"A1", "A2", "A3"};
        
        MultipleChoiceExam mcExam(1, "Object Oriented programming", 70, mcQuestions, mcAnswers);
        EssayExam essayExam(2, "Computer Support", 30, "Discuss the BIOS vs UEFI interface in computers");

        // Display and grade MultipleChoiceExam
        mcExam.display();
        cout << "\n Grading MultipleChoiceExam:" << endl;
        double mcScore = mcExam.gradeExam();
        cout << "Score: " << mcScore << "%" << endl;

        // Display and grade EssayExam
        essayExam.display();
        cout << "\n Grading EssayExam:" << endl;
        double essayScore = essayExam.gradeExam();
        cout << "Score: " << essayScore << "%" << endl;
        
      //using catch blocks to handle specific exception types 
    } catch (const Exam::InvalidExamDurationException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const MultipleChoiceExam::GradingErrorException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const EssayExam::GradingErrorException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error occurrence: " << e.what() << endl;
    }

    return 0;
}