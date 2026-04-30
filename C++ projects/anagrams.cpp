
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


void swap(vector<int> &v, int i, int j)
{
	int temp = v.at(i);
	v.at(i) = v.at(j);
	v.at(j) = temp;
}

void permute(vector<vector<int>> &result, vector<int> & v, int left, int right)
{
	if (left == right) {
		result.push_back(v);
	}
	else {
		for (int i = left; i <= right; i++) {
			swap(v, i, left);
			permute(result, v, left + 1, right);
			swap(v, i, left);
		}
	}
}

// Returns all the permutations of the input vector v
vector<vector<int>> computePermutations(vector<int> v)
{
    vector<vector<int>> results;
    // Call recursive function to compute the permutations
    permute(results, v, 0, v.size() - 1);
    return results;
}

int main() 
{   
    ifstream fin;
    fin.open("wordlist.txt");
    vector<string> allWords; // Creat an vector to store the names in the file given

    while (fin) { // use the while loop to store string in vector
        string fileName;
        fin >> fileName;
        allWords.push_back(fileName); 
    }

    // Statistics File
    ofstream fout("statistics.txt");
    ifstream fin_stat;
    fin_stat.open("statistics.txt");
    vector<int> numbers;

    //Ask user to type in input file name
    string name;
    cout << "Enter file name (.txt) (or Q to quit):  ";
	cin  >> name;
    
    vector<string> nameOfFiles;

    int total = 1; //total number of permutations output
    int numOfChars = name.length();
    int count = 0; // number of strings user input
    int tempUpperCount=0; 
    int unique = 0;// number of unique strings in the input file


    //Reading in the input file
	while ((name != "Q") && (name != "q")) {
        string temp = name + ".txt";
        ifstream fin2;
        fin2.open(temp);
        // count the number of uppercase letters converted to lowercase letters
        // convert the uppercase to lowercase
        while(fin2.eof()==1){
            fin2>>name;
            vector<char> chars;
            int tempCharCount=name.length();

            for(int i=0;i<tempCharCount;i++){
                if(isupper(name.at(i))){
                    name.at(i)= tolower(name[i]);
                    tempUpperCount+=1;
                }
                chars.push_back(name.at(i));
            }
        }

        // use the binary search to check if the user input is in the wordlist file
        if (binary_search(allWords.begin(), allWords.end(), name)){
            ofstream fout(temp); // create a file(.txt) named by the user input
            cout << temp << endl;
            nameOfFiles.push_back(name); // save the name in the nameOfFiles vector
            count++;
        }
        else{
            break;
        }

        // count the unique strings in the input file
        for(int i=0; i<count; i++){
            if(name==nameOfFiles[i]){
                unique++;
            }
        }
        
        // Number of characters processed from the input file not counting duplicates
        for(int i=0; i<name.length(); i++){
            for(int j=name.length(); j>=0; j--){
                if(name[i]==name[j]){
                    numOfChars=numOfChars-1;
                }
            }
        }

        // total number of permutations output is total

        // Average number of permutations output per input string – to two decimal places

        // Total number of anagrams output is count

        total++;
        cout << "Enter file name (.txt) (or Q to quit):  ";
        cin >> name;

        while (fin2.fail()) {
            // Read in all parts of data 
            string tempWord;
            cin >> tempWord;
            if(fin2.fail()){
                break;
            }
            allWords.push_back(tempWord);
        }
        fin2.close();
    }

    numbers.push_back(unique);
    numbers.push_back(numOfChars);
    numbers.push_back(tempUpperCount);
    numbers.push_back(total);
    //numbers.push_back(); average did not found
    numbers.push_back(count);
    //numbers.push_back(); average did not found

    // output the numbers vector
    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << endl;
    }
    fin.close();
    
    return 0;
}



