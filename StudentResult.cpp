#include<iostream>
using namespace std;
class StudentResult{
    int studentID;
    string studentName;
    int marks[5];
    int totalMarks;
    float averageMarks;
    string resultStatus;

    public:

        void enterDetails()
        {
            cout<<"Enter ID : ";
            cin>>studentID;
            cout<<"Enter name : ";
            cin>>studentName;
            cout<<"Enter marks : \n";
            for(int i=0;i<5;i++)
            {
                cout<<"Enter marks of "<<(i+1)<<" subject : ";
                cin>>marks[i];
            }
            cout<<endl;
        }

        void calculateResult()
        {
            totalMarks = 0;
            for(int i=0;i<5;i++)
            {
                totalMarks += marks[i];
            }
            averageMarks = ((float)totalMarks/(float)5);
            for(int i=0;i<5;i++)
            {
                if(marks[i]<35)
                {
                    resultStatus = "FAIL";
                    break;
                }
                else resultStatus = "PASS";
            }
        }

        void dup(int ans)
        {
            studentID = ans;
        }
        void displayResult()
        {
            cout<<"ID : "<<studentID;
            cout<<endl;
            cout<<"Name : "<<studentName;
            cout<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<"Marks of "<<(i+1)<<" subject : "<<marks[i];
                cout<<endl;
            }
            calculateResult();
            cout<<"Total Marks : "<<totalMarks;
            cout<<endl;
            cout<<"Average Marks : "<<averageMarks;
            cout<<endl;
            cout<<"Status : "<<resultStatus;
            cout<<endl;
        }

        int stdid()
        {
            return studentID;
        }
};

int main()
{
    StudentResult obj[100];
    int n,a=0,stdu,p,idd;
    bool flag = 0,check=0;
    while(1)
    {
        cout<<"Press 0. To Exit\n";
        cout<<"Press 1. To Add student details\n";
        cout<<"Press 2. To Display Result\n";
        cout<<"Press 3. To Search Studnet\n";
        cin>>n;
        if(n==1)
        {
            if(flag==0)
            {
                cout<<"Enter how many students you want to add : ";
                cin>>stdu;
                for(int i=0;i<stdu;i++)
                {
                    obj[i].enterDetails();
                    cout<<endl;
                }
                flag = 1;
            }
            else if(flag==1)
            {
                cout<<"Enter new no of student : ";
                cin>>a;
                for(int i=stdu;i<(stdu+a);i++)
                {
                    obj[i].enterDetails();
                    cout<<endl;
                }
                stdu+=a;
            }
                    for(int i=0;i<stdu-1;i++)
                    {
                        for(int j=i+1;j<stdu;j++)
                        {
                            if(obj[i].stdid()==obj[j].stdid())
                            {
                                obj[j].dup(0);
                            }
                        }
                    }
        }

        else if(n==2)
        {
            cout<<"\n";
            cout<<"Press 1. To display single student details\n";
            cout<<"Press 2. To display entire student details\n";
            cin>>p;

            if(p==1)
            {
                cout<<endl;
                cout<<"Enter Student id : ";
                cin>>idd;
                for(int i=0;i<stdu;i++)
                {
                    if(idd==obj[i].stdid()) obj[i].displayResult();
                    cout<<endl;
                }
            }
            else if(p==2)
            {
                cout<<endl;
                for(int i=0;i<stdu;i++)
                {
                    if(obj[i].stdid()==0) continue;
                    else obj[i].displayResult();
                    cout<<endl;
                }
            }
        }
        else if(n==3)
        {
            cout<<endl;
            cout<<"Enter Student ID : ";
            cin>>idd;
            for(int i=0;i<stdu;i++)
            {
                if(idd==obj[i].stdid())
                {
                    cout<<"Student Present\n";
                    check=1;
                    break;
                }
                if(check==1) break;
            }
            if(check==0) cout<<"Student Not Present\n";
        }
        else if(n==0)
        {
            cout<<"Thankyou:)\n";
            return 0;
        }
    }
    return 0;
}