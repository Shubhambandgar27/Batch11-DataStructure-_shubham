//book library.
#include<iostream>
#include<string.h>
#include<windows.h>

using namespace std;

class Books
{
  public:
  int bookid;
  char bname[20];
  char aname[20];
  
  Books *next;

};
int main()
{    int choice;
    Books *current;
    Books *first=NULL;
    Books *fptr;
    Books *temp;



   while(1)
    {
        cout<<"\n 1.Add Book.";
        cout<<"\n 2.show Books.";
        cout<<"\n 3.Delete Book in Between";

        cout<<"\n Enter choice :";
        cin>>choice;
       

        cout<<"wait..";
        Sleep(500);
        system("cls");
        switch(choice)
        {
            case 1:
                     current=new Books();
                      if(first==NULL)
                      first=fptr=current;
                      else
                     { fptr->next=current;
                      fptr=current;}

                      cout<<"\n Add Book Id :";
                      cin>>current->bookid;

                      cout<<"\n Add Book Name :";
                      cin>>current->bname;

                      cout<<"\n Add Author Name :";
                      cin>>current->aname;
                  break;
            case 2:
                 
                    if(first==NULL)
                      {cout<<"\n List is Empty !";
                        break;}
                    else
                      { 
                        temp=first;
                        while(1)
                     {
                        cout<<"\n "<<temp->bookid<<"\t"<<temp->bname<<"\t"<<temp->aname;
                        if(temp->next==NULL)
                        break;

                        temp=temp->next;}
                      }
                  break;
           
            case 3:
                   int ubookid;
                    cout<<"\n Enter book id to delete :";
                   cin>>ubookid;
                  
                   
                   if(first==NULL)
                   {
                     cout<<"\n List is Empty.";
                   }
                   else if(ubookid==first->bookid )
                   {
                     temp=first;
                     first=temp->next;
                     delete temp;
                     cout<<"\n First Book Deleted.";
                     
                   }
                   else
                   {
                      Books *x=NULL, *tf=NULL;
                      temp= first->next;
                      tf=first;
                    
                    
                     while(1)
                     {
                         if(ubookid==temp->bookid)
                       {
                         x=temp;
                         break;
                       }

                       if(temp->next==NULL)
                       break;

                       tf=temp;
                       temp=temp->next;
                     }
                     if(x==NULL)
                     {
                       cout<<"\n Book is not found.";
                     }
                     else
                     {
                       tf->next=x->next;
                       delete x;
                       cout<<"\n Book is deleted.";
                     }
                   }
                  break;
                   
            default :
                  cout<<"\n Invalid Choice! ";
        }
    }
    return 0;

}