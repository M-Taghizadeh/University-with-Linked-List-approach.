#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct student//my list
{
    int id;
    student *link;

    struct Personality
    {
        string name;
        string familly;
        string field;
        string gender;

    }person;

    struct Course
    {
        int year=0;
        int term_number=0;
        float term_average=0;
        string dars1=" ";//data structure
        int score1=0;
        string dars2=" ";//system analyses
        int score2=0;
        string dars3=" ";//signal & system
        int score3=0;
        string dars4=" ";//data base
        int score4=0;
    }course;
}*head=NULL;


void insert_student();//ثبت نام دانشجوی جدید
void selection_course();//اطلاعات ترمی دانشجو
void delete_course();//حذف درس
void insert_score();
void delete_student();//حإف  دانشجو
void search_information();//نمایش اطلاعات دانشجو بر اساس id(کارنامه)
void report_avarage();//گذارش بر اساس معدل
void report_failure();//گذارش بر اساس افرادی که دروسی را افتاده اند
void report_conditional();//گذارش بر اساس دانشجو های مشروطی
void show_document();//نشان دادن تمامی اطلاعات موجود در لیست
int exit();//خروج از برنامه

int main()
{
    //menu:
    int ch;
    while(ch)
    {
        system("color 3");
        cout<<setw(11)<<"<MENU>\n"<<endl;
        cout<<"1.Insert student \n"<<endl;
        cout<<"2.Selection course \n"<<endl;
        cout<<"3.Delete course \n"<<endl;
        cout<<"4.Insert score\n"<<endl;
        cout<<"5.Delete student\n"<<endl;
        cout<<"6.Search student information\n"<<endl;
        cout<<"7.Reports for best average\n"<<endl;
        cout<<"8.Reports for failure students\n"<<endl;
        cout<<"9.Reports for conditional students\n"<<endl;
        cout<<"10.Show documents\n"<<endl;
        cout<<"11.Exit\n"<<endl;
        cout<<"choice option : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                system("cls");
                insert_student();
                break;
            }
        case 2:
            {
                system("cls");
                selection_course();
                break;
            }
        case 3:
            {
                system("cls");
                delete_course();
                break;

            }
        case 4:
            {
                system("cls");
                insert_score();
                break;

            }
        case 5:
            {
                system("cls");
                delete_student();
                break;
            }
        case 6:
            {
                system("cls");
                search_information();
                break;
            }
        case 7:
            {
                system("cls");
                report_avarage();
                break;
            }
        case 8:
            {
                system("cls");
                report_failure();
                break;
            }
        case 9:
            {
                system("cls");
                report_conditional();
                break;
            }
        case 10:
            {
                system("cls");
                show_document();
                break;
            }
        case 11:
            exit();
            {
                system("cls");
                ch=exit();
                getch();
            }
        default:
            system("cls");
            break;
        }
    }

    getch();
}

void insert_student()
{
    cout<<"<ENROLL PAGE>\n\n";
    system("color 6");
    student *p;
    student *q;
    student *temp;
    q=head;
    p=new student;

    cout<<"Enter ID of student : ";
    cin>>p->id;
    cout<<"\n[Personality Information]"<<endl;
    cout<<"Enter name:\t";
    cin>>p->person.name;
    cout<<"Enter family:\t";
    cin>>p->person.familly;
    cout<<"Enter field:\t";
    cin>>p->person.field;
    cout<<"\n[Course information]"<<endl;
    cout<<"Entering Year:\t";
    cin>>p->course.year;
    cout<<"Term number:\t";
    cin>>p->course.term_number;

if(q==NULL)
{
        p->link=NULL;
        head=p;
}

else
{
        p->link=NULL;
        if(p->id <= q->id)//اضافه کردن به ابتدای لیست
        {
            if(head==NULL)
                head=p;
            else
            {
                p->link=head;
                head=p;
            }
        }
        else//اضافه کردن عنصر به جای مشخص
        {
            while(q->link!=NULL)
            {
                temp=q;
                q=q->link;
                if(p->id <= q->id)
                    break;
            }

            if(q->link==NULL)//اضافه کردن عنصر به انتهای لیست
            {
                while(q->link!=NULL)
                {
                    q=q->link;
                }
                q->link=p;
            }

            else//اضافه کردن عنصر به جای مشخص
            {
                p->link=q;
                temp->link=p;
            }
        }
}

getch();
system("cls");
}

void selection_course()
{
    system("color 2");
    student *p;
    int key;

    cout<<"WLCOME TO THE SELECTION COURSE PAGE\n"<<endl;
    cout<<"Enter your ID:";
    cin>>key;
    p=head;

    if(p==NULL)//if list was empty
        cout<<"list is empty";

    else
    {
        while(p->link!=NULL)
        {
            if(p->id==key)
            {
                break;
            }
            p=p->link;
        }

        if(p->id==key)
        {
            cout<<"SELECTION UNIT PAGE\n\n-----------------------";
            cout<<"\nCourse list :\n";
            cout<<"1.data structure\n2.system analysis\n3.signal & system\n4.data base\n-----------------------"<<endl;

            int code;
            cout<<"Enter code of lesson:";
            cin>>code;
            switch(code)
            {
            case 1:
                p->course.dars1="data structure";
                cout<<"you take "<<p->course.dars1<<endl;
                break;
            case 2:
                p->course.dars2="system analysis";
                cout<<"you take "<<p->course.dars2<<endl;

                break;
            case 3:
                p->course.dars3="signal & system";
                cout<<"you take "<<p->course.dars3<<endl;

                break;
            case 4:
                p->course.dars4="data base";
                cout<<"you take "<<p->course.dars4<<endl;

                break;
            }

        }

        else
            cout<<"Student not found ";
    }
getch();
system("cls");
}

void delete_course()
{
    system("color 5");
    cout<<"<DELETE SCOURE PAGE>\n\n";
    student *p;
    p=head;
    int key;

    if(p==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        cout<<"Enter ID : ";
        cin>>key;
        while(p->link!=NULL)
        {
            if(p->id==key)
            {
                break;
            }
            p=p->link;
        }

        if(p->id==key)
        {
            if(p->course.dars1!=" "||p->course.dars2!=" "||p->course.dars3!=" "||p->course.dars4!=" ")
            {
                cout<<"\nCourse list :\n";
                if(p->course.dars1!=" ")
                {
                    cout<<"1.data structure"<<endl;
                }
                if(p->course.dars2!=" ")
                {
                    cout<<"2.system analysis"<<endl;
                }
                if(p->course.dars3!=" ")
                {
                    cout<<"3.signal & system"<<endl;
                }
                if(p->course.dars4!=" ")
                {
                    cout<<"4.data base"<<endl;
                }
                int code;
                cout<<"Enter code of lesson that you want delete"<<endl;
                cin>>code;
                switch(code)
                {
                case 1:
                    {
                        cout<<p->course.dars1<<" has been deleted";
                        p->course.dars1=" ";
                        break;
                    }
                case 2:
                    {
                        cout<<p->course.dars2<<" has been deleted";
                        p->course.dars2=" ";
                        break;
                    }
                case 3:
                    {
                        cout<<p->course.dars3<<" has been deleted";
                        p->course.dars3=" ";
                        break;
                    }
                case 4:
                    {
                        cout<<p->course.dars4<<" has been deleted";
                        p->course.dars4=" ";
                        break;
                    }
                }
            }
            else
            {
                cout<<"oops!\nThere is no lesson.";

            }

        }
        else
        cout<<"student not found.";
    }

    getch();
    system("cls");
}

void delete_student()
{
    system("color 8");
    student *temp;
    student *q;
    int found=0;

    q=head;

    if(q==NULL)//اگر لیست خالی بود
    {
        cout<<"list is empty.";
    }
    else
    {
        int key;
        cout<<"Enter id of student : ";
        cin>>key;
        if(q->id==key)//حذف در ابتدای لیست
        {
            temp=head;
            head=head->link;
            cout<<"student deleted.";
            delete q;
        }

        else//حإف از وسط لیست
        {
            while(q->link!=NULL)
            {
                temp=q;
                q=q->link;
                if(q->id==key)
                {
                    found=1;
                    break;
                }
            }

            if(found==0)
            {
                cout<<"ID not found!!!";
            }
            else
            {
                if(q->link==NULL)//حإف از انتهای لیست
                {
                    temp->link=NULL;
                    cout<<"student deleted.";
                    delete q;
                }

                else//حذف از اواسط لیست
                {
                    temp->link=q->link;
                    cout<<"student deleted.";
                    delete q;
                }
            }
        }
    }

getch();
system("cls");
}


void insert_score()
{
    system("color 7");
    int a=0,b=0,c=0,d=0;//baraye nomerat
    int x1=0,x2=0,x3=0,x4=0;//baraye tedad nomerat
    float avg;
    int key;

    cout<<"INSERT SCORE PAGE\n";

    student *p;
    p=head;
    if(p==NULL)
    {
        cout<<"list is empty!";
    }
    else
    {
        cout<<"Enter ID :\n";
        cin>>key;
        while(p->link!=NULL)
        {
            if(p->id==key)
            {
                break;
            }
            p=p->link;
        }
        if(p->id==key)
        {
            if(p->course.dars1!=" "||p->course.dars2!=" "||p->course.dars3!=" "||p->course.dars4!=" ")
            {
                if(p->course.dars1!=" ")
                {
                    cout<<"insert score for "<<p->course.dars1<<" : ";
                    cin>>p->course.score1;
                    a=p->course.score1;
                    x1++;
                }
                if(p->course.dars2!=" ")
                {
                    cout<<"insert score for "<<p->course.dars2<<" : ";
                    cin>>p->course.score2;
                    b=p->course.score2;
                    x2++;
                }
                if(p->course.dars3!=" ")
                {
                    cout<<"insert score for "<<p->course.dars3<<" : ";
                    cin>>p->course.score3;
                    c=p->course.score3;
                    x3++;
                }
                if(p->course.dars4!=" ")
                {
                    cout<<"insert score for "<<p->course.dars4<<" : ";
                    cin>>p->course.score4;
                    d=p->course.score4;
                    x4++;
                }


                cout<<"\nAverage : ";
                avg=(a+b+c+d)/(x1+x2+x3+x4);
                p->course.term_average=avg;
                cout<<p->course.term_average;

            }
        }
        else
            cout<<"student not found";
    }

getch();
system("cls");

}

void search_information()
{
    system("color F");
    student *p;
    p=head;

    int key;
    cout<<"Enter ID : ";
    cin>>key;
if(p==NULL)
{
    cout<<"list is empty!";
}
else
{

    while(p->link!=NULL)
    {
        if(p->id==key)
        {
            break;
        }
        p=p->link;
    }

    if(p->id==key)
    {
            cout<<"ID :"<<p->id<<endl;
            cout<<"\n[Personality information]"<<endl;
            cout<<"name :"<<p->person.name<<endl;
            cout<<"family:"<<p->person.familly<<endl;
            cout<<"field:"<<p->person.field<<endl;
            cout<<"\n[Course information]"<<endl;
            cout<<"entering year:"<<p->course.year<<endl;
            cout<<"Term number:"<<p->course.term_number<<endl;

            cout<<"Course list:\n";
            if(p->course.dars1!=" ")
            {
                cout<<p->course.dars1;
                if(p->course.score1!=0)
                    cout<<" : "<<p->course.score1<<endl;
            }
            if(p->course.dars2!=" ")
            {
                cout<<p->course.score2;
                if(p->course.score2!=0)
                    cout<<" : "<<p->course.score2<<endl;
            }
            if(p->course.dars3!=" ")
            {
                cout<<p->course.dars3;
                if(p->course.score3!=0)
                    cout<<" : "<<p->course.score3<<endl;
            }
            if(p->course.dars4!=" ")
             {
                cout<<p->course.dars4;
                if(p->course.score4!=0)
                    cout<<" : "<<p->course.score4<<endl;
             }

            if(p->course.term_average!=0)
            {
                cout<<"Term average:"<<p->course.term_average<<endl;
            }
    }
    else
        cout<<"student not found!";

}
    getch();
    system("cls");
}

void report_avarage()
{
    system("color 8");
    cout<<"<best average in each year>\n";
    student *p;
    p=head;
    float maximum=0;
    if(p==NULL)
    {
        cout<<"list is empty!";
    }
    else
    {
        int key;//entire year
        cout<<"\nEnter Entire Year : ";
        cin>>key;

        while(p!=NULL)
        {

            if(key==p->course.year && p->course.term_average!=0 && p->course.term_average>maximum)
            {
               maximum=p->course.term_average;
            }
            p=p->link;
        }
        if(maximum!=0)
            cout<<"The best average in this Year : "<<maximum;
        else
            cout<<"not found any average";
    }


    getch();
    system("cls");
}

void report_failure()
{
    system("color 2");
    student *p;
    p=head;

    if(p==NULL)//لیست خالی
    {
        cout<<"list is empty";
    }
    else
    {
        cout<<"<Failure list>\n";

        while(p!=NULL)
        {
            if((p->course.score1!=0&&p->course.score1<10)||(p->course.score2!=0&&p->course.score2<10)||(p->course.score3!=0&&p->course.score3<10)||(p->course.score4!=0&&p->course.score4<10))
            {
                cout<<"ID : "<<p->id<<"\tfamily : "<<p->person.name<<endl;
                if(p->course.score1<10 && p->course.score1!=0)
                {
                    cout<<p->course.dars1<<" : "<<p->course.score1<<endl;
                }
                if(p->course.score2<10 && p->course.score2!=0)
                {
                    cout<<p->course.dars2<<" : "<<p->course.score2<<endl;
                }
                if(p->course.score3<10 && p->course.score3!=0)
                {
                    cout<<p->course.dars3<<" : "<<p->course.score3<<endl;
                }
                if(p->course.score4<10 && p->course.score4!=0)
                {
                    cout<<p->course.dars4<<" : "<<p->course.score4<<endl;
                }

            }
            p=p->link;
        }
    }

getch();
system("cls");

}
void report_conditional()
{
    system("color 9");
    student *p;
    p=head;
    if(p==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        cout<<"<List of conditional students>\n";
        while(p!=NULL)
        {
            if(p->course.term_average!=0 && p->course.term_average<12)
            {
                cout<<"ID : "<<p->id<<"\tfamily : "<<p->person.familly<<"\taverage : "<<p->course.term_average<<endl;
            }
            p=p->link;
        }
    }

    getch();
    system("cls");

}

void show_document()
{
    system("color F");
    student *temp;

    temp=head;

    cout<<"\t\t\t\t\tstudents information\n\n"<<endl;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }

    else
    {
        for(int i=1;temp!=NULL;i++)
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"student"<<i<<endl;
            cout<<"ID :"<<temp->id<<endl;
            cout<<"\n[Personality information]"<<endl;
            cout<<"name :"<<temp->person.name<<endl;
            cout<<"family:"<<temp->person.familly<<endl;
            cout<<"field:"<<temp->person.field<<endl;
            cout<<"\n[Course information]"<<endl;
            cout<<"entering year:"<<temp->course.year<<endl;
            cout<<"Term number:"<<temp->course.term_number<<endl;

            cout<<"Course list:\n";
            if(temp->course.dars1!=" ")
            {
                cout<<temp->course.dars1;
                if(temp->course.score1!=0)
                    cout<<" : "<<temp->course.score1<<endl;
            }
            if(temp->course.dars2!=" ")
            {
                cout<<temp->course.score2;
                if(temp->course.score2!=0)
                    cout<<" : "<<temp->course.score2<<endl;
            }
            if(temp->course.dars3!=" ")
            {
                cout<<temp->course.dars3;
                if(temp->course.score3!=0)
                    cout<<" : "<<temp->course.score3<<endl;
            }
            if(temp->course.dars4!=" ")
             {
                cout<<temp->course.dars4;
                if(temp->course.score4!=0)
                    cout<<" : "<<temp->course.score4<<endl;
             }

            if(temp->course.term_average!=0)
            {
                cout<<"Term average:"<<temp->course.term_average<<endl;
            }
            cout<<"\n-----------------------------------------------------"<<endl;
            temp=temp->link;
        }
    }

getch();
system("cls");

}


int exit()
{

    system("color 17");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tproduct by mohammad taghizadeh..";
    return false;
}
