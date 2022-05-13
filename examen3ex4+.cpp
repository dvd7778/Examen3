#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

// Externs to avoid lack of prototype warnings
extern string removeNonAlpha(string word);
extern int findLastPattern(string sentence, string pattern);
extern string insertPattern(string sentence, string pattern);

/* Exercise 1
 * Returns a copy of the given sentence with ALL non-alphanumeric characters removed.
 * If the string has no such characters it should return an identical copy of original sentence.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */
string removeNonAlpha(string word) {

    // YOUR CODE
    if(word.size()<2){
        if(isalnum(word[0])){
            return word;
        }
        return "";
    }
    if(isalnum(word[0])){
        return word.front() + removeNonAlpha(word.substr(1, word.size()-1));
    }
    return removeNonAlpha(word.substr(1, word.size()-1));
}



/* Exercise 2
 * Returns the position of the LAST occurrence of the given pattern in the given sentence.
 * Returns -1 if the pattern does not appear in the sentence.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */
int findLastPatternHelper(string s, string p, int n){
    if(s.find(p) == std::string::npos && n<1){
        return n;
    }
    if(s.find(p) == std::string::npos && n>=1){
        return 0;
    }
    n++;
    if(n>1){
        return s.find(p) + p.size()*1 + findLastPatternHelper(s.substr(s.find(p)+p.size(), s.size()-s.find(p)-p.size()), p, n);
    }
    return s.find(p) + p.size()*n + findLastPatternHelper(s.substr(s.find(p)+p.size(), s.size()-s.find(p)-p.size()), p, n);
}
int findLastPattern(string sentence, string pattern) {

    // YOUR CODE
    return findLastPatternHelper(sentence, pattern, -1);
}

int findLastPattern(string sentence, string pattern) {

    // YOUR CODE
    if(sentence.find(pattern) == std::string::npos){
        return -1;
    }
    return sentence.find(pattern) + findLastPattern(sentence.substr(sentence.find(pattern)+pattern.size(), sentence.size()-sentence.find(pattern)-pattern.size()), pattern);
}

/* Exercise 3
 * Returns a copy of the given sentence with the given pattern inserted in between
 * each pair of letters.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */
string insertPattern(string sentence, string pattern) {

    // YOUR CODE
    if(sentence.size()<2){
        return sentence;
    }
    return sentence.front() + pattern + insertPattern(sentence.substr(1,sentence.size()-1), pattern);
}


  
  
int main() {

    cout << "\nExercise 1" << endl;
    cout << "0Hello1!Hello2$Hello3 removed nonalpha: " << removeNonAlpha("0Hello1!Hello2$Hello3") << endl;
    cout << "_0Hello1!Hello2$Hello3% removed nonalpha: " << removeNonAlpha("_0Hello1!Hello2$Hello3%") << endl;
    cout << "*&^%$#~`(*&@% removed nonalpha: " << removeNonAlpha("*&^%$#~`(*&@%") << endl;
    cout << endl;

    cout << "\nExercise 2" << endl;
    cout << "Position of last 'he' in 'hello': " << findLastPattern("hello", "he") << endl;
    cout << "Position of last 'llo' in 'hello': " << findLastPattern("hello", "llo") << endl;
    cout << "Position of last 'ell' in 'hello': " << findLastPattern("hello", "ell") << endl;
    cout << "Position of last 'lo' in 'hellolo': " << findLastPattern("hellolo", "lo") << endl;
    cout << "Position of last 'hh' in 'hhhh': " << findLastPattern("hhhh", "hh") << endl;
    cout << endl;

    cout << "\nExercise 3" << endl;
    cout << "HelloHelloHello with _ inserted: " << insertPattern("HelloHelloHello", "_") << endl;
    cout << "He with _ inserted: " << insertPattern("He", "_") << endl;
    cout << "H with _ inserted: " << insertPattern("H", "_") << endl;
    cout << endl;


}