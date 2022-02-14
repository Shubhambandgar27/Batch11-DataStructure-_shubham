/* WAP to maintain book-library using singly linked list data structure
data - bookid, bookname, author
menus - Add Book, Show Book, Delete Book, Exit
implementation - 
	a. using switch case without functions
	b. using switch case with functions
	c. using sample input and output
	   example:
	    #1
	    *2
 	    101
            HTML
	    James
	    102
	    CSS
	    John
	    #1
	    *1
	    103
	    JavaScript
	    Gosling
	    #2
	    ....... show all available linked list of book details
	    #3
	    105
	    False
	    #3
	    101
	    True */
#include<iostream>
#include<string.h>

using namespace std;
class Book
{
   public:
  int bookid;
  char bname[20];
  char aname[20];
  
  Book *next;

   
};

int main()
{
    int choice,no;
    Book *current;
    Book *first=NULL;
    Book *fptr;
    Book *temp;
    while(1)
    {

        cin>>choice;
       
        switch(choice)
        {
            case 1:
              cin>>no;
              for(int i=1;i<=no;i++)
              {
                     current=new Book();
                      if(first==NULL)
                        first=fptr=current;
                      else
                     { 
                        fptr->next=current;
                        fptr=current;
                      }

                      cin>>current->bookid;

                      cin>>current->bname;

                      cin>>current->aname;
              }
                  break;
            case 2:
                    if(first==NULL)
                      {
                        break;}
                    else
                      { 
                        temp=first;
                        while(1)
                       {
                          cout<<"\n "<<temp->bookid<<"\t"<<temp->bname<<"\t"<<temp->aname;
                            if(temp->next==NULL)
                               break;
                           temp=temp->next;
                        }
                      }
                  break;
           
            case 3:
                   int ubookid;
                   
                   cin>>ubookid;
                  
                   
                   if(first==NULL)
                   {
                    break;
                   }
                   else if(ubookid==first->bookid )
                   {
                     temp=first;
                     first=temp->next;
                     delete temp;
                     
                   }
                   else
                   {
                      Book *x=NULL, *tf=NULL;
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
                       cout<<"\nFalse.";
                       break;
                     }
                     else
                     {
                       tf->next=x->next;
                       delete x;
                       cout<<"\nTrue";
                       
                     }
                   }
                  break;
                   
            default :
                exit(0);
        }
    }
    return 0;



}