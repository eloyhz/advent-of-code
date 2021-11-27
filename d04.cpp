#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cctype>

using namespace std;

bool is_valid_year(string year_string, int least, int most)    {
    try {
        int year = stoi(year_string);
        if (year < least || year > most) {
            return false;
        }
    }   catch(const std::invalid_argument& e)   {
        return false;
    }
    return true;    
}

bool is_valid_passport(map<string, string> &fields) {
    for (string key : {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"})  {
        if (fields.count(key) == 0) {
            return false;
        }
        if (key == "byr" && !is_valid_year(fields[key], 1920, 2002))   {
            return false;
        }
        else if (key == "iyr" && !is_valid_year(fields[key], 2010, 2020))   {
            return false;
        }
        else if (key == "eyr" && !is_valid_year(fields[key], 2020, 2030))   {
            return false;
        }
        else if (key == "hgt")    {
            int value;
            try {
                value = stoi(fields[key].substr(0, fields[key].length()-2));
            }   catch(const std::invalid_argument& e)   {
                return false;
            }
            string units = fields[key].substr(fields[key].length()-2);
            if (units == "cm" && (value < 150 || value > 193))  {
                return false;
            }
            else if (units == "in" && (value < 59 || value > 76))   {
                return false;
            }
            else if (units != "in" && units != "cm")    {
                return false;
            }
        }
        else if (key == "hcl")  {
            string value = fields[key];
            if (value.length() != 7 || value[0] != '#') {
                return false;
            }
            for (int i = 1; i <= 6; i++)
                if (!isxdigit(value[i]))    {
                    return false;
                }
        }
        else if (key == "ecl")  {
            string value = fields[key];
            set<string> s = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
            if (s.count(value) == 0)    {
                return false;
            }
        }
        else if (key == "pid")  {
            if (fields[key].length() != 9)  {
                return false;
            }
            for (char c : fields[key])  {
                if (!isdigit(c))    {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()  {
    string line;
    int count = 0;
    map<string, string> fields;
    while (getline(cin, line)) {
        if (line == "") {
            if (is_valid_passport(fields))  {
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
                string value = passport.substr(4);
                fields[key] = value;
            }
        }
    }
    if (is_valid_passport(fields))  {
        count++;
    }

    cout << count << endl;
}