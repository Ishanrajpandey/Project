#include <stdio.h>
#include <string.h>
#include<ctype.h>

// Function to ask a question and get the user's answer
int askQuestion(char question[], char options[][100], char correctAnswer)
{
    char guess;
    int i;
    
	printf("--------------------------------------\n");
    printf("%s\n", question);
    printf("--------------------------------------\n");
    for (i = 0; i < 4; i++) 
	{
        printf("%s\n", options[i]);
    }

    printf("Your answer: ");
    scanf(" %c", &guess); // Added space before %c to skip any leading whitespace
	
	guess = toupper(guess);
	
    if (guess == correctAnswer) 
	{
        printf("Correct!\n");
        return 1; // Return 1 for correct answer
    } 
	else 
	{
		printf("Wrong! The correct answer is option %c\n", correctAnswer);
        return 0; // Return 0 for wrong answer
    }
}

int main() 
{
    int score = 0;

    // Questions, options, and correct answers
    char questions[][100] = {
        "who is considered the biggest drug lord of all time ?",
        "Who is the author of Revolution 2020 ?",
        "What is the darkest colour in the world ?"
    };

    char options[][4][100] = {
        {"A. Khun Sa", "B. Frank Lucas", "C. Pablo Escobar", "D. Joaquin Guzman"},
        {"A. J.K. Rowling", "B. Chetan Bhagat", "C. Jane Austen", "D. Harper Lee"},
        {"A. Black", "B. Dark black", "C. Eigengrau", "D. Vantablack"}
    };

    char answers[3] = {'C', 'B', 'D'};
	
	printf("QUIZ GAME \n");
    // Ask each question and update the score
    for (int i = 0; i < 3; i++) 
	{
        score += askQuestion(questions[i], options[i], answers[i]);
    }
	
	printf("-------------------------------------\n");
    // Print final score
    printf("Your final score is %d out of 3.\n", score);
	printf("-------------------------------------\n");
    return 0;
}

