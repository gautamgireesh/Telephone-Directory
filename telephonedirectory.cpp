#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
struct date
{
	int dd,mm,yyyy;
};
class tel
{

   public:
   date d;
	char name[25],sex,persem[40],resad[80],offem[40];
   int resph,mobno,resfax,offph,offfax;
   void inputdata()
   {
         date d;
			cout<<"Enter name of contact: "; gets(name);
			cout<<"Enter sex(M/F): "; cin>>sex;
			cout<<"Enter personal email: "; gets(persem);
			cout<<"Enter residential address: "; gets(resad);
			cout<<"Enter date of birth\n";
         	cout<<"Enter Day [1-31]  ? "; cin>>d.dd;
      		cout<<"Enter Month [1-12]? "; cin>>d.mm;
      		cout<<"Enter Year [YYYY] ? "; cin>>d.yyyy;
			cout<<"Enter Residential phone number: "; cin>>resph;
			cout<<"Enter mobile number: "; cin>>mobno;
			cout<<"Enter Residential fax number: "; cin>>resfax;
			cout<<"Enter office phone number: "; cin>>offph;
			cout<<"Enter office fax number: "; cin>>offfax;
         cout<<"Enter office email: "; gets(offem);
   }
   void displaydata()
   {
         date d;
   		cout<<"Name       = "<<name<<endl;
   		cout<<d.dd<<"/"<<d.mm<<"/"<<d.yyyy<<endl;
         cout<<"Sex        = "<<sex<<endl;
         cout<<"Res Phone  = "<<resph<<endl;
         cout<<"Mobile     = "<<mobno<<endl;
         cout<<"Res Fax    = "<<resfax<<endl;
         cout<<"Email      = "<<persem<<endl;
         cout<<"Address    = "<<resad<<endl;
         cout<<"Off Phone  = "<<offph<<endl;
         cout<<"Off Fax    = "<<offfax<<endl;
         cout<<"Off Email  = "<<offem<<endl;
   }
		void display2()
      {
      	printf("%-20s %c %8i %8i %8i %40s\n", name, sex, resph, mobno, resfax, resad);
      }
      void display3()
      {
      	printf("%-20s %c %8i %8i %8i %40s\n", name, sex, resph, mobno, resfax, persem);
      }
      void display4()
      {
      	printf("%-20s %c %8i %8i\n", name, sex, offph, offfax);
      }
      void display5()
      {
         date d;
      	printf("%-20s %c %02i-%02i-%4i %8i %40s %40s\n", name, sex, d.dd, d.mm, d.yyyy, mobno, persem, offem);
      }
   	char *retname(){ return name;}
		char *retperemail(){return persem;}
      char *retoffemail(){return offem;}
		char *retadd(){return resad;}
		int retresph(){return resph;}
		int retmob(){return mobno;}
		int retresfax(){return resfax;}
		int retoffph(){return offph;}
		int retofffax(){return offfax;}
      void updateresphone(int rphone) { resph=rphone; }
      void updatemob(int mo) { mobno=mo; }
      void updateresfax(int rfax) { resfax=rfax; }
      void updateoffphone(int ophone) { offph=ophone; }
      void updateofffax(int ofax) { offfax=ofax; }
      void updateperemail(char em[]) { strcpy(persem, em); }
      void updateaddr(char addr[]) { strcpy(resad, addr); }
      void addrec();
      void del();
      void cd();void modify();void search();void sort();void displaymenu();
};
void tel::addrec()
{
	ofstream f1("TELE.DAT",ios::binary|ios::app);
   tel T;
   int n;
   cout<<"No. customer datas to be added: ";cin>>n;
   for(int k=0;k<=n;k++)
   {
   	T.inputdata();
      f1.write((char*)&T,sizeof(T));
      cout<<endl;
   }
   f1.close();
   cout<<"Press any key to return";getch();
}
void tel::del()
{
	char name[20];
	cout<<"Enter name whose record must be deleted: ";gets(name);
	tel T;
	ifstream f1("TELE.DAT", ios::binary);
	ofstream f2("NEWTELE.DAT", ios::binary);
	int f=0;
	clrscr();
	while(f1.read((char*)&T, sizeof(T)))
		if(strcmpi(name,T.retname())==0)
		{
			cout<<"Record deleted from the file!"<<endl;
			f=1;
		}
		else
			f2.write((char*)&T,sizeof(T));
	if(f==0)
		cout<<"Record not found in the existing telephone directory."<<endl;
	f1.close();
	f2.close();
	remove("TELE.DAT");
	rename("NEWTELE.DAT", "TELE.DAT");
	cout<<"\n\n Press any key to return "; getch();
}
void tel::modify()
{
	char name[25];
   tel T;
   fstream f1("TELE.DAT",ios::binary|ios::in|ios::out);
   cout<<"Enter name of customer whose data you wish to modify: ";gets(name);
   int f=0;
   while(f1.read((char*)&T,sizeof(T)))
   	if(strcmpi(name,T.retname())==0)
      {
      	f=1;int m;
         cout<<"Customer found successfully!/n";
         cout<<"Which data would you like to modify? "<<endl;
         cout<<"Enter 1 to modify residential phone number: "<<endl;
         cout<<"Enter 2 to modify mobile number: "<<endl;
         cout<<"Enter 3 to modify residential fax number: "<<endl;
         cout<<"Enter 4 to modify office phone number: "<<endl;
         cout<<"Enter 5 to modify office fax number: "<<endl;
         cout<<"Enter 6 to modify personal e-mail: "<<endl;
         cout<<"Enter 7 to modify residential address: "<<endl;
         cin>>m;
         if(m==1)
         {
            int q;
         	cout<<"Enter new residential phone number: ";cin>>q;
            T.updateresphone(q);f1.write((char*)&T,sizeof(T));
         }
         if(m==2)
         {
            int q;
         	cout<<"Enter new mobile number: ";cin>>q;
            T.updatemob(q);f1.write((char*)&T,sizeof(T));
         }
         if(m==3)
         {
            int q;
         	cout<<"Enter new residential fax number: ";cin>>q;
            T.updateresfax(q);f1.write((char*)&T,sizeof(T));
         }
         if(m==4)
         {
            int q;
         	cout<<"Enter new office phone number: ";cin>>q;
            T.updateoffphone(q);f1.write((char*)&T,sizeof(T));
         }
         if(m==5)
         {
            int q;
         	cout<<"Enter new office fax number: ";cin>>q;
            T.updateofffax(q); f1.write((char*)&T,sizeof(T));
         }
         if(m==6)
         {
            char q[40];
         	cout<<"Enter new personal e-mail: ";cin>>q;
            T.updateperemail(q);f1.write((char*)&T,sizeof(T));
         }
         if(m==7)
         {
            char q[80];
         	cout<<"Enter new residential address: ";cin>>q;
            T.updateaddr(q);f1.write((char*)&T,sizeof(T));
         }
      }


         if(f==0)
         	cout<<"Record not found in the existing telephone directory."<<endl;
         f1.close();
      	cout<<"\n\n Press any key to return";getch();
}
void tel::search()
{
	tel T[10];
   int m;
   ifstream f1("TELE.DAT",ios::binary);
   cout<<"On what basis would you like to search? "<<endl;
   cout<<"Enter 1: To search on the basis of Name"<<endl;
   cout<<"Enter 2: To search on the basis of Phone number"<<endl;
   cout<<"Enter 3: To search on the basis of Fax number"<<endl;
   cout<<"Enter 4: To search on the basis of Mobile number"<<endl;
   cout<<"Enter 5: To search on the basis of E-mail ID"<<endl;
   cin>>m;

   	if(m==1)
      {
         int k;
      	char searchname[30];int f=0;
         cout<<"Enter name to be searched: ";gets(searchname);
         for(k=0;k<10;k++)
         {
      		while(f1.read((char*)&T,sizeof(T))&&f!=1)
         	if(strcmpi(searchname,T[k].retname())==0)
         	f=1;
         }
         if(f==1)
         {
				cout<<"Record found!\n "<<endl;
            T[k].displaydata();
         }
         else if(f==0)
         	cout<<"Record not found in the existing telephone directory.";
      }
      if(m==2)
      {
         int k;
      	int searchph,f=0;
         cout<<"Enter residential number to be searched: ";cin>>searchph;
         for(k=0;k<10;k++)
         {
            while(f1.read((char*)&T,sizeof(T)))
         	if(searchph==T[k].retresph())
         	f=1;
         }
         if(f==1)
         {
            cout<<"Record found!\n "<<endl;
            T[k].displaydata();
         }
         else if(f==0)
         	cout<<"Record not found in the existing telephone directory.";
      }
      if(m==3)
      {
         int k;
      	int searchfax,f=0;
         cout<<"Enter residential fax number to be searched: ";cin>>searchfax;
         for(k=0;k<10;k++)
         {
            while(f1.read((char*)&T,sizeof(T)))
         	if(searchfax==T[k].retresfax())
         	f=1;
         }
         if(f==1)
         {
         	cout<<"Record found!\n "<<endl;
            T[k].displaydata();
         }
         else if(f==0)
         	cout<<"Record not found in the existing telephone directory.";
      }
      if(m==4)
      {
      	int k;
         int searchmobno,f=0;
         cout<<"Enter mobile number to be searched: ";cin>>searchmobno;
         for(k=0;k<10;k++)
         {
            while(f1.read((char*)&T,sizeof(T)))
         	if(searchmobno==T[k].retmob())
         	f=1;
         }
         if(f==1)
         {
            cout<<"Record found!\n "<<endl;
            T[k].displaydata();
         }
         else if(f==0)
         	cout<<"Record not found in the existing telephone directory.";
      }
      if(m==5)
      {
         int k;
      	char searchemail[40],f=0;
         cout<<"Enter Email-ID to be searched: ";gets(searchemail);
         for(k=0;k<10;k++)
         {
            while(f1.read((char*)&T,sizeof(T)))
         	if(strcmpi(searchemail,T[k].retperemail())==0)
         	f=1;
         }
         if(f==1)
         {
            cout<<"Record found!\n "<<endl;
            T[k].displaydata();
         }
         else if(f==0)
         	cout<<"Record not found in the existing telephone directory.";
      }
   f1.close();
   cout<<"\n\n Press any key to return ";getch();
}
void tel::sort()
{
   tel T[10];
   ifstream f1("TELE.DAT",ios::binary);
	int m;
   cout<<"Enter one of the following numbers to sort a particular data\n\n";
   cout<<"Enter 1: Sort on the basis of name"<<endl;
	cout<<"Enter 2: Sort on the basis of Phone number"<<endl;
   cout<<"Enter 3: Sort on the basis of Fax number"<<endl;
   cout<<"Enter 4: Sort on the basis of E-mail ID"<<endl;
   cin>>m;

   if(m==1)
   {
      int k;
   	for(int x=1; x<10; x++)
      {
      	for(k=0; k<10-x; k++)
         {
            while(f1.read((char*)&T,sizeof(T)))
         	if (strcmpi(T[k].retname(),T[k+1].retname())>0)
            	{
                     tel p=T[k];
                     T[k]=T[k+1];
                     T[k+1]=p;
            	}
         }
      }
		cout<<"Sorted on the basis of names"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display2();
      f1.close();
   }
   if(m==2)
   {
      int q,k;
      cout<<"Enter 1:Sort by Residential number\n";
      cout<<"Enter 2:Sort by Mobile number\n";
      cout<<"Enter 3:Sort by Office number\n";
      cin>>q;
      if(q==1)
      	{
   			for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (T[k].retresph()>T[k+1].retresph())
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
		cout<<"Sorted on the Residential Numbers"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display3();
      	}
      if(q==2)
      	{
            int k;
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (T[k].retmob()>T[k+1].retmob())
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Mobile Numbers"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display3();
      	}
      if(q==3)
      	{
            int k;
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (T[k].retoffph()>T[k+1].retoffph())
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Office Numbers"<<endl;
      		for(int x=0;x<10;x++)
      			T[k].display4();
      		f1.close();
         }
      }
	 if(m==3)
    {
    	int q,k;
      cout<<"Enter 1:Sort by Residential fax\n";
      cout<<"Enter 2:Sort by Office fax\n";
      cin>>q;
      if(q==1)
      	{
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (T[k].retresph()>T[k+1].retresph())
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Residential Fax"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display3();
      	}
      if(q==2)
      	{
            int k;
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (T[k].retofffax()>T[k+1].retofffax())
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Office Fax"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display4();
      	}
      f1.close();
    }
    if(m==4)
    {
    	int q,k;
      cout<<"Enter 1:Sort by Personal E-mail ID\n";
      cout<<"Enter 2:Sort by Office E-mail ID\n";
      cin>>q;
      if(q==1)
      	{
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
         					if (strcmpi(T[k].retperemail(),T[k+1].retperemail())>0)
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Personal E-mail"<<endl;
      for(int x=0;x<10;x++)
      	T[k].display5();
      	}
      if(q==2)
      	{
            int k;
         	for(int x=1; x<10; x++)
      			{
      				for(k=0; k<10-x; k++)
         				{
                        while(f1.read((char*)&T,sizeof(T)))
                        if (strcmpi(T[k].retoffemail(),T[k+1].retoffemail())>0)
            					{
                     			tel p=T[k];
                     			T[k]=T[k+1];
                     			T[k+1]=p;
            					}
         				}
      			}
            cout<<"Sorted on the Office E-mail"<<endl;
      for(int x=0;x<10;x++)
			T[k].display5();
      	}
      f1.close();
    }
}
/*void tel::cd()
{
   date d;
	fstream f1("TELE.DAT",ios::binary|ios::in);
   tel T;
   int p;
   while(f1.read((char*)&T,sizeof(T)))
   {
   if(d.dd>=1&&d.dd<=31&&d.mm>=1&&d.mm<=12)
   	p=0;
   else
   	p=1;
   }
   if(p==1)
   	cout<<"Entered date is not valid";
   if(p==0)
   	cout<<"Entered date is vaild";
   f1.close();
	clrscr();
   getch();
}  */
void displayfile1()
{
	ifstream fin("TELE.DAT", ios::binary);
   tel T;
   clrscr();
   int x=1;
   while (fin.read((char*)&T, sizeof(T)))
   {
   	T.displaydata();
      cout<<endl;
      if (x%2==0)
      {
      	cout<<"Press any to continue ...";
         getch();
         clrscr();
      }
      x++;
   }
   fin.close();
   getch();
}
void displayfile2()
{
	ifstream fin("TELE.DAT", ios::binary);
   tel T;
   clrscr();
   while (fin.read((char*)&T, sizeof(T)))
   	T.display2();
   fin.close();
   getch();
}
void displayfile3()
{
	ifstream fin("TELE.DAT", ios::binary);
   tel T;
   clrscr();
   while (fin.read((char*)&T, sizeof(T)))
   	T.display3();
   fin.close();
   getch();
}
void displayfile4()
{
	ifstream fin("TELE.DAT", ios::binary);
   tel T;
   clrscr();
   while (fin.read((char*)&T, sizeof(T)))
   	T.display4();
   fin.close();
   getch();
}
void displayfile5()
{
	ifstream fin("TELE.DAT", ios::binary);
   tel T;
   clrscr();
   while (fin.read((char*)&T, sizeof(T)))
   	T.display5();
   fin.close();
   getch();
}
void tel::displaymenu()
{
	int ch;
   do
   {
   	clrscr();
      cout<<"Display Menu\n";
      cout<<"_______________________________________________________\n";
      cout<<"1. Display Complete Details\n";
      cout<<"2. Display Name, Sex, Res Phone, Mobile, Res Fax, Res Address\n";
      cout<<"3. Display Name, Sex, Res Phone, Mobile, Res FAx, Personal E-mail\n";
      cout<<"4. Display Name, Sex, Office Phone, Office Fax\n";
      cout<<"5. Display Name, Name, Sex, Date, Movile, Personal E-mail, Office E-mail\n";
      cout<<"0. Return to Main Menu\n";
      cout<<"Choice[0-5]? "; cin>>ch;
      switch (ch)
      {
			case 1: displayfile1(); break;
			case 2: displayfile2(); break;
			case 3: displayfile3(); break;
			case 4: displayfile4(); break;
         case 5: displayfile5(); break;
      }
   }
   while (ch);
}
void main()
{
	cout<<"WELCOME TO TELEPHONE DIRECTORY MANAGEMENT SYSTEM"<<endl;
	cout<<"________________________________________________"<<endl;
	int ch; tel t;
	do
	{
		clrscr();
		cout<<"1. Add records\n";
		cout<<"2. Delete records\n";
		cout<<"3. Modification of records\n";
		cout<<"4. Searching of records\n";
		cout<<"5. Sorting of records\n";
      cout<<"6. Display Menu\n";
      //cout<<"7. Check validation of date\n";
 		cout<<"0. Exit\n";
      cout<<"Choice[0-10]? "; cin>>ch;
		switch(ch)
		{
			case 1: t.addrec(); break;
			case 2: t.del(); break;
			case 3: t.modify(); break;
			case 4: t.search(); break;
			case 5: t.sort(); break;
         case 6: t.displaymenu(); break;
         //case 7: t.cd(); break;
		}
	}
   while(ch);
}
/*OUTPUT
1. Add records
2. Delete records
3. Modification of records
4. Searching of records
5. Sorting of records
6. Display Menu
0. Exit
Choice[0-10]? 1
No. customer datas to be added: 2
Enter name of contact: Gautam
Enter sex(M/F): M
Enter personal email: gautamgireesh@gmail.com
Enter residential address: Mahboula,Kuwait
Enter date of birth
Enter Day [1-31]  ? 26
Enter Month [1-12]? 4
Enter Year [YYYY] ? 2000
Enter Residential phone number: 23714957
Enter mobile number: 67055260
Enter Residential fax number: 2387659
Enter office phone number: 23899098
Enter office fax number: 23534123
Enter office email: gipillai20@koc.com

Enter name of contact: Harold
Enter sex(M/F): M
Enter personal email: harold@gmail.com
Enter residential address: Abu halifa,Kuwait
Enter date of birth
Enter Day [1-31]  ? 20
Enter Month [1-12]? 9
Enter Year [YYYY] ? 1995
Enter Residential phone number: 23577665
Enter mobile number: 66804510
Enter Residential fax number: 23234354
Enter office phone number: 54654345
Enter office fax number: 33322217
Enter office email: harold27@koc.com

Enter name of contact: Kumar
Enter sex(M/F): F
Enter personal email: kumar@gmail.com
Enter residential address: Salmiya,Kuwait
Enter date of birth
Enter Day [1-31]  ? 2
Enter Month [1-12]? 2
Enter Year [YYYY] ? 2001
Enter Residential phone number: 23567890
Enter mobile number: 99878765
Enter Residential fax number: 44556644
Enter office phone number: 55776649
Enter office fax number: 98789876
Enter office email: kumar1212@equate.com

Press any key to return
*/