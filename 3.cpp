/* Adding List Items in Singly Linked List */
#include<iostream>

using namespace std;
class player
{
    public:
    int playerid;
    char name[20];

    player *next;

    void addplayer()
    {
        cout<<"\n Enter player ID :";
        cin>>playerid;

        cout<<"\n Enter player name :";
        cin>>name;
    }
    void showPlayer()
    {
        cout<<"\n"<<playerid<<"\t "<<name;
    }
};
player *current;
player *first=NULL;
player *fptr;

player* addNodeLast()
{
   current= new player();
    if(first==NULL)
    {
        first=fptr=current;
    }
    else
    {
        fptr->next=current;
        fptr=current;
    }
    current->addplayer();
    current->next=NULL;
    return current;
}
void addNodeFirst()
{
    current= new player();

    if(first==NULL)
    {
        first = fptr =current;
        first->next=NULL;
    }
    else 
    {
        current->next=first;
        first=current;
        current=fptr;
    }
    first->addplayer();
}
void addNodeAfter()
{
    player *x=NULL, *x1=NULL,*temp=first;
    int uplayer_id;

    cout<<"\n Enter player Id After which you want to add new player:";
    cin>>uplayer_id;

    while(1)
    {
        if(uplayer_id==temp->playerid)
        {
            x=temp;
            break;
        }
        if(temp->next==NULL)
          break;
         temp=temp->next;
    }
    if(x==NULL)
    {
        cout<<"\n Player not found :";
    }
    else if(uplayer_id==current->playerid)
    {
        addNodeLast();
    }
    else
    {
       x1=x->next;
       current=new player;

       x->next=current;
       current->next=x1;

       current->addplayer();
       current=fptr;
    }

}
void showNodes()
{
	if(first==NULL)
	{
		cout<<"\n List is Empty!";
	}
	else
	{
		cout<<"\n Players are:";
		player *temp = first;
		
		while(1)
		{
			temp->showPlayer();
			
			if(temp->next==NULL)
				break;
				
			temp = temp->next;
		}
	}
}
int main()
{
    int choice;

    while(1)
    {
        cout<<"\n 1. Add player at End";
		cout<<"\n 2. Add player at First";
		cout<<"\n 3. Add player After";
		cout<<"\n 4. Show list";
		cout<<"\n 5. Exit";

        cout<<"\n Enter choice:";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                    addNodeLast();
                    cout<<"\n Player Added at the end :";
                    break;
            case 2:
                    addNodeFirst();
                    cout<<"\n Player Added at First:";
                    break;
            case 3:
                    addNodeAfter();
                    cout<<"\n Player Added .";
                     break;
            case 4:
                    showNodes();
                    break;
            case 5:
                    exit(0);
        }
    }
}