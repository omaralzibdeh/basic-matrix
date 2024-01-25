#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void printlist(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int llsize(Node *n)

{
    int count = 0;
    Node *holder = n;
    while (holder != NULL)
    {
        count++;
        holder = holder->next;
    }
    return count;
}
void insert(Node **n, int hold)

{
    Node *temp = new Node;
    temp->data = hold;
    temp->next = *n;
    *n = temp;
}
float sumOfNodes(Node *n)
{
    Node *holder = n;
    float sum = 0;
    while (holder != NULL)
    {
        sum += holder->data;
        holder = holder->next;
    }
    return sum;
}
float getter(Node *a, int hold)
{
    Node *current = a;
    int count = 0;
    float coward = 0;
    while (current != NULL)
    {
        if (count == hold)
        {
            coward = current->data;
            break;
        }
        count++;
        current = current->next;
    }
    return coward;
}
void deleteList(Node **n)
{
    Node *next = NULL;
    Node *current = *n;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *n = NULL;
}
Node *arrayToList(vector<float> v)

{
    Node *n = NULL;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        for (int x = v.size() - 1; x >= 0; x--)
        {

            insert(&n, v[x]);
        }
        break;
    }
    return n;
}
int digitcounter(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

string addtwonodes(Node *a, Node *b, int collums, int rows, int coll2, int rows2)
{
    stringstream ss;
    // ss << "";
    if (collums == coll2 && rows == rows2)
    {
        int size = collums * rows;
        int reapcount = 0;
        int countme = 0;
        int holder = 0;
        int widthholder = 3;

        Node *ansholder = NULL;
        Node *ans = NULL;
        while (a != NULL)
        {

            float adder = 0.0;
            adder = a->data + b->data;
            insert(&ansholder, adder);
            a = a->next;
            b = b->next;
        }

        for (int i = 0; i < llsize(ansholder); i++)
        {
            float holder = getter(ansholder, i);
            insert(&ans, holder);
        }

        for (int i = 0; i < size; i++)
        {
            if (digitcounter(getter(ans, i)) < digitcounter(getter(ans, i + 1)))
            {
                holder = digitcounter(getter(ans, i + 1));
                widthholder = holder + 2;
            }
        }
        for (int i = 0; i < size; i++)
        {
            reapcount++;
            ss << fixed << setprecision(1) << setw(widthholder) << getter(ans, i);
            if (reapcount <= collums - 1)
            {
                ss << " ";
            }

            if (reapcount == collums)
            {
                ss << endl;
                reapcount = 0;
            }
        }
    }
    return ss.str();
}

string subtwonodes(Node *a, Node *b, int collums, int rows, int coll2, int rows2)
{
    stringstream ss;
    ss << "";
    if (collums == coll2 && rows == rows2)
    {
        int size = collums * rows;
        int reapcount = 0;
        int countme = 0;
        int holder = 0;
        int widthholder = 3;

        Node *ansholder = NULL;
        Node *ans = NULL;
        while (a != NULL)
        {

            float subber = 0.0;
            subber = a->data - b->data;
            insert(&ansholder, subber);
            a = a->next;
            b = b->next;
        }

        for (int i = 0; i < llsize(ansholder); i++)
        {
            float holder = getter(ansholder, i);
            insert(&ans, holder);
        }

        for (int i = 0; i < size; i++)
        {
            if (digitcounter(getter(ans, i)) < digitcounter(getter(ans, i + 1)))
            {
                holder = digitcounter(getter(ans, i + 1));
                widthholder = holder + 2;
            }
        }
        for (int i = 0; i < size; i++)
        {

            reapcount++;
            ss << fixed << setprecision(1) << setw(widthholder + 1) << getter(ans, i);
            if (reapcount <= collums - 1)
            {
                ss << " ";
            }

            if (reapcount == collums)
            {
                ss << endl;
                reapcount = 0;
            }
        }
    }
    return ss.str();
}
string multwonodes(Node *a, Node *b, int coll, int rows, int coll2, int rows2)
{

    int rowcoll = 0;
    int anssize = 0;
    if (rows2 == coll)
    {
        rowcoll = rows2;
    }
    anssize = rowcoll * 2;
    float row;
    float collum;
    int size = coll * rows;
    int size2 = coll2 * rows2;
    stringstream ss;
    Node *holderow = NULL;
    for (int i = 0; i < size; i++) // rows of m1
    {
        row = getter(a, i);
        insert(&holderow, row);
    }

    int position = 0;
    Node *holdercoll = NULL;
    for (int i = 0; i < size2; i++) // columns of m2
    {
        for (int x = 0; x < size2; x++)
        {
            if (x == position)
            {
                collum = getter(b, x);
                position = position + coll2;
                insert(&holdercoll, collum);
            }
            if (llsize(holdercoll) == size2)
            {
                break;
            }
        }
        position = 0;
        position = i + 1;
    }
    int reapcount = 0;
    Node *multiholder = NULL;

    /////////////////////////////////////////////////////////////////////////////////////////////
    Node *rowhold = NULL;
    Node *collhold = NULL;
    Node *ansholder = NULL;
    Node *ffans = NULL;
    float multi = 0;
    int rowcount = 0;
    int collcount = 0;
    for (int i = 0; i < size; i++)
    {
        float capstone = getter(holderow, i); /// holder
        insert(&rowhold, capstone);           /// push_back
        if (llsize(rowhold) == rowcoll)       // vector.size()
        {
            for (int x = 0; x < size; x++) // columns/////////////////////////
            {
                float capstone2 = getter(holdercoll, x);
                insert(&collhold, capstone2);
                if (llsize(collhold) == rowcoll)
                {
                    for (int t = 0; t < rowcoll; t++) ////////////////////themulti//////////////////
                    {
                        //cout << getter(rowhold, t) << " ";
                        multi = getter(rowhold, t) * getter(collhold, t);
                        insert(&ansholder, multi); // pushback
                        if (llsize(ansholder) == rowcoll)
                        {
                            for (int g = 0; g < rowcoll; g++)
                            {
                                float add = sumOfNodes(ansholder); // adds all nodes
                                insert(&ffans, add);
                            }
                            deleteList(&ansholder); // vector.clear
                        }
                    }
                    deleteList(&collhold);
                }
            }
            deleteList(&rowhold);
        }
    }
    //printlist(ffans);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Node *ans = NULL;
    //printlist(ffans);cout<<endl;
;    for (int i = llsize(ffans) - 1; i >= 0; i = i - rowcoll) // instead of 3x number it only prints first occurane
    {
        float ansholder = getter(ffans, i);
        insert(&ans, ansholder);
    }

    int countme = 0;
    int holder = 0;
    int widthholder;
    stringstream ss1;

    for (int i = 0; i < llsize(ans); i++)
    {
        if (digitcounter(getter(ans, i)) < digitcounter(getter(ans, i + 1)))
        {
            holder = digitcounter(getter(ans, i + 1));
            widthholder = holder + 2;
        }
    }
    
    int counter=0;
    while (counter<llsize(ans))
    {

        reapcount++;
        ss1 << fixed << setprecision(1) << setw(widthholder) << getter(ans, countme);
        if (reapcount <= rowcoll - 1)
        {
            ss1 << " ";
        }
        if (reapcount == coll2)
        {
            ss1 << endl;
            reapcount = 0;
        }
        countme++;
        counter++;
    }
    stringstream space;
    space << "";
    return ss1.str();
}

string dettwonodes(Node *a, int coll, int rows)
{
    string hold = "holder";
    return hold;
}
string tratwonodes(Node *n, int row, int coll)
{
    stringstream ss;
    int count = 0;
    int space = 0;
    float result;
    int coward = row;
    Node *hold = NULL;
    hold = new Node();
    hold = n;
    stringstream trat;
    int holder = 0;
    int widthholder = 0;
    for (int i = 0; i < llsize(n); i++)
    {
        if (digitcounter(getter(n, i)) < digitcounter(getter(n, i + 1)))
        {
            holder = digitcounter(getter(n, i + 1));
            widthholder = holder + 2;
        }
    }
    for (int i = 0; i < coll; i++)
    {

        n = hold;
        while (n != NULL)
        {

            // col checker basically
            if (coward % row == count)
            {
                result = n->data;
                ss << fixed << setprecision(1) << setw(widthholder) << result;
                if (space <= coll - 1)
                {
                    ss << " ";
                    space = 0;
                }
                space++;
            }

            n = n->next;
            coward++;
        }
        count++;

        ss << endl;
    }
    return ss.str();
}

int main(int argc, char *argv[])
{
    
    string arg1;
    if (argc > 1)
    {
        arg1=(argv[1]);
    }
    if (arg1 == "add" || arg1 == "sub" || arg1 == "mul")
    {

        fstream infile;
        infile.open(argv[2]);
        ///////////////////////////counter////////////////////////
        string hold;
        string hold2;
        vector<float> counter;
        vector<float> counter2;
        vector<vector<float>> ll;
        string buffer;
        int countrowm1 = 0;
        int countcollumnm1 = 0;
        int countrowm2 = 0;
        int countcollumnm2 = 0;
        while (getline(infile, hold))
        {
            countrowm1++;
            stringstream ss(hold);
            int num = 0;
            // row
            while (ss >> num)
            {
                counter.push_back(num);
                countcollumnm1++;
            }
        }
        infile.close();
        infile.open(argv[3]);
        while (getline(infile, hold2))
        {
            countrowm2++;
            stringstream ss(hold2);
            int num = 0;
            // row
            while (ss >> num)
            {
                counter2.push_back(num);
                countcollumnm2++;
            }
        }
        infile.close();
        countcollumnm1 = countcollumnm1 / countrowm1;
        countcollumnm2 = countcollumnm2 / countrowm2;
        Node *m2 = arrayToList(counter2);
        Node *m1 = arrayToList(counter);
        ofstream outfile;
        if (arg1 == "add")
        {
            outfile.open(argv[4]);
            outfile << addtwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);
            outfile.close();
        }
        if (arg1 == "sub")
        {
            outfile.open(argv[4]);
            outfile << subtwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);
            outfile.close();
        }
        if (arg1 == "mul")
        {
            outfile.open(argv[4]);
            outfile << multwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);
            outfile.close();
        }
    }

    if (arg1 == "tra" || arg1 == "det")
    {
        fstream infile;
        infile.open(argv[2]);
        ///////////////////////////counter////////////////////////
        string hold;
        vector<float> counter;
        vector<float> counter2;
        vector<vector<float>> ll;
        string buffer;
        int countrowm1 = 0;
        int countcollumnm1 = 0;
        while (getline(infile, hold))
        {
            countrowm1++;
            stringstream ss(hold);
            int num = 0;
            // row
            while (ss >> num)
            {
                counter.push_back(num);
                countcollumnm1++;
            }
        }
        infile.close();
        Node *m1 = arrayToList(counter);
        ofstream outfile;
        if (arg1 == "tra")
        {
            outfile.open(argv[3]);
            outfile << tratwonodes(m1, countrowm1, countcollumnm1);
            outfile.close();
        }
        if (arg1 == "det")
        {
            outfile.open(argv[3]);
            outfile << dettwonodes(m1,countcollumnm1, countrowm1);
            outfile.close();
        }
    }
    
    fstream infile;
    infile.open("test.txt");
    ///////////////////////////counter////////////////////////
    string hold;
    string hold2;
    vector<float> counter;
    vector<float> counter2;
    vector<vector<float>> ll;
    string buffer;
    int countrowm1 = 0;
    int countcollumnm1 = 0;
    int countrowm2 = 0;
    int countcollumnm2 = 0;
    while (getline(infile, hold))
    {
        countrowm1++;
        stringstream ss(hold);
        int num = 0;
        // row
        while (ss >> num)
        {
            counter.push_back(num);
            countcollumnm1++;
        }
    }
    infile.close();
    infile.open("test2.txt");
    while (getline(infile, hold2))
    {
        countrowm2++;
        stringstream ss(hold2);
        int num = 0;
        // row
        while (ss >> num)
        {
            counter2.push_back(num);
            countcollumnm2++;
        }
    }
    infile.close();
    countcollumnm1 = countcollumnm1 / countrowm1;
    countcollumnm2 = countcollumnm2 / countrowm2;
    Node *m2 = arrayToList(counter2);
    Node *m1 = arrayToList(counter);

    ///////////////////////////////////////output////////////////////////////

    /////////////////////////////////////MULTIPLICATION/////////////////////////////
    cout << "add" << endl;
    // cout << addtwonodes(m1, m2, countcollumnm1) << endl;
    cout << addtwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);

        cout << "sub" << endl;
    cout << subtwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);
    cout << "multiply" << endl;
    cout<<multwonodes(m1, m2, countcollumnm1, countrowm1, countcollumnm2, countrowm2);
    // tratwonodes(m2, countcollumnm2, countrowm2);
    
}
