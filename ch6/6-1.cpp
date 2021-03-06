#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cout; using std::string; using std::endl; using std::iterator; 
using std::vector; using std::max; using std::cin;
typedef vector<string> vecstr;

string::size_type width(const vecstr& v)
{
    string::size_type maxlen = 0;
    for (vecstr::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vecstr frame(const vecstr& v) {
    vecstr ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vecstr::const_iterator it = v.begin(); it != v.end(); it++) {
        ret.push_back("* " + *it + string(maxlen - (*it).size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

vecstr vcat(const vecstr& top, const vecstr& bottom)
{
    vecstr ret = top;

    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

vecstr hcat(const vecstr& left, const vecstr& right)
{
    vecstr ret;

    string::size_type width1 = width(left) + 1;

    vecstr::const_iterator itl = left.begin(), itr = right.begin();

    while (itl != left.end() || itr != right.end()) { 
        string s;

        if (itl != left.end()) {
            s = *itl;
            itl++;
        }

        s += string(width1 - s.size(), ' ');

        if (itr != right.end()) {
            s += *itr;
            itr++;
        }

        ret.push_back(s);
    }
    return ret;
}

vecstr center(const vecstr &centervec)
{
    int maxlen = width(centervec);

    vecstr newcentervec;
    int secondspaces;
    for (string i : centervec) {
        secondspaces = maxlen - i.size() - ((maxlen - i.size()) / 2);
        newcentervec.push_back("* " + string((maxlen - i.size()) / 2, ' ') + i + string(secondspaces, ' ') + " *");
    }

    return newcentervec;
}

int main()
{

    cout << "How many words do you want to frame?: ";
    int amnt;
    cin >> amnt;
    cout << "\n";

    if (amnt < 1) {
        return 1;
    }

    vecstr wordvec;
    string word;
    for (int i = 0; i < amnt; i++) {
        cout << "Enter a word: ";
        cin >> word;
        wordvec.push_back(word);
        cout << "\n";
    }

    cout << "frame\n" << endl;

    const vecstr newvec = frame(wordvec);
    for (string line : newvec) {
        cout << line << endl;
    }

    cout << endl;

    cout << "vertical cocatenation frame number 2\n" << endl;

    const int newvecsz = newvec.size();
    vecstr topvec, botvec;
    topvec.insert(topvec.end(), newvec.begin(), newvec.begin() + newvecsz / 2);
    botvec.insert(botvec.end(), newvec.begin() + newvecsz / 2, newvec.end());
    
    vecstr vervec = vcat(topvec, botvec);
    for (string line : vervec) {
        cout << line << endl;
    }

    cout << "\n";

    cout << "vertical cocatenation\n" << endl;

    vervec = vcat(wordvec, frame(wordvec));
    for (string line: vervec) {
      cout << line << endl;
    }

    cout << endl;

    cout << "horizontal cocatentation\n" << endl;

    const vecstr horvec = hcat(wordvec, frame(wordvec));
    for (string line : horvec) {
        cout << line << endl;
    }

    cout << "center\n" << endl;

    const vecstr cenvec = center(wordvec);
    for (string line : cenvec) {
        cout << line << endl;
    }

   return 0;
}