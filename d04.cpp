#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

bool is_valid(set<string> &fields) {
    for (string s : {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"})  {
        if (fields.count(s) == 0) {
            return false;
        }
    }
    return true;
}

int main()  {
    string line;
    int count = 0;
    set<string> fields;
    while (getline(cin, line)) {
        if (line == "") {
            if (is_valid(fields))  {
                count++;
            }
            fields.clear();
        }
        else    {
            // construct a stream from the line
            stringstream ss(line);
            string passport;
            while (getline(ss, passport, ' ')) {
                string key = passport.substr(0, 3);
                fields.insert(key);
            }
        }
    }
    if (is_valid(fields))  {
        count++;
    }

    cout << count << endl;
}