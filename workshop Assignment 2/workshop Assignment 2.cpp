#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// Open and save the file as a string called fileString.
/// Word count and sentence count set based on number of spaces and line ends.
/// A variable for word is made that will hold the current word in the string stream.
/// Create a vector made of pairs called wordlist, the first data type is a sting (the word), the second is an integer, (how many times the word occurs)
/// 
/// Start a loop that continues while each word from the string stream is compared to each word in the string.
/// With each loop a new word is selected and thus the word count increments.
/// Removing punctuation as well as counting sentences, 
/// Create a variable finalChar that is set to the last character of the string in question.
/// Use this to see if the last character is the end of a sentence, 
/// Increment if it is and remove the punctuation.
/// Define a boolean variable "found"
/// iterate through the list of words
/// If statement to check if the word being compared matches the one in the string stream.
/// If so set the found boolean to true and break the loop.
/// if it isn't found add the word to the vector pair.
/// Printing the list of words and how many times it occurs.
/// close the word stream and print the amount of words and sentences.
/// </summary>

int main()
{
    ifstream wordStream("C:\\Users\\angbu\\OneDrive\\Documents\\Lincoln\\Year 2\\Advanced programming\\Week 2\\Workshop\\input.txt");
    int wordCount = 0, sentenceCount = 0; 
    string word;
    vector <pair<string, int>> wordList;

        while (wordStream >> word)
        {
            wordCount++;
            char finalChar = word.back();
            if (finalChar == '!' || finalChar == '?' || finalChar == '.' || finalChar == ',')
            {
                word.pop_back();
                if (finalChar != ',')
                    sentenceCount++;
            }

            bool found = false;

            for (size_t i = 0; i < wordList.size(); i++) 
            {
                if (wordList.at(i).first == word) 
                {
                    wordList.at(i).second += 1; 
                    found = true;
                }
            }
            if (!found)
                wordList.push_back(make_pair(word, 1));
        }
    for (size_t i = 0; i < wordList.size(); i++)
    {
        cout << wordList[i].first << " " << wordList[i].second << endl;
    }

    wordStream.close();
    cout << "\nThe number of words are: " << wordCount << endl;
    cout << "\nThe number of sentences are: " << sentenceCount << endl;

    return 0;
}