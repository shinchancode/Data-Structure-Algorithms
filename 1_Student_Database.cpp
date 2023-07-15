/* AARTI RATHI 
Topic: Student database and sorting 
My website - https://shinchancode.github.io/3d-react-portfolio/
*/ 


/* Problem Statement : 

Consider a student database of SE-IT class(at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)
a. Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)
b. Arrange list of students alphabetically. (Use Insertion sort)
c. Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d. Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.
e. Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)*/

#include<iostream> 
using namespace std;

//Structure for student data
struct student 
{ 
 int roll; 
 string name; 
 float sgpa; 
}; 

void show1(student *a[], int n) //Printing the data of students
{ 
 for (int i=0;i<n;i++) 
 { 
   cout<<a[i]->roll<<" "; 
   cout<<a[i]->name<<" "; 
   cout<<a[i]->sgpa<<"\n"; 

 } 
} 

void show2(student *a[], int n) //Printing in reverse order
{ 
 for (int i=n-1;i>n-11;i--) 
 { 
   cout<<a[i]->roll<<" "; 
   cout<<a[i]->name<<" "; 
   cout<<a[i]->sgpa<<"\n"; 
 } 
} 

void bubSort(student *a[],int n) //Bubble sort
{ student *t=new student; 
 int check=1; 
 for (int i=0;i<n-1;i++) 
 { 

   for (int j=0;j<n-i-1;j++) 
   { 
     if (a[j]->roll>a[j+1]->roll) 
     { 
       t= a[j]; 
       a[j] = a[j+1]; 
       a[j+1] = t; 
     } 
     else 
     { 
       check=0; 
     } 
   } 
   if (check=0) 
   { 
     break; 
   } 
 } 
} 

void inserSort(student *a[],int n)  //Insertion Sort for sorting
{ 
 int j; 
 student *t; 
 string k; 
 for (int i=0;i<n;i++) 
 { 
   k=a[i]->name; 
   t=a[i]; 
   j=i-1; 
   while(j>=0 && a[j]->name>k) 
   { 
     a[j+1]=a[j]; 
     j--; 
   } 
   a[j+1]=t; 

 } 
} 

int partition (student *a[], int l, int u) //Partition for Quicksort
{ 
 student *t; 
 
 float p=a[l]->sgpa; 
 int start=l,end=u; 
 { 
   while(a[start]->sgpa <= p && start<u) 
   { 
     start++; 
   } 
   while (a[end]->sgpa>p) 
   { 
     end--; 
   } 

   if(start < end) 
   { 
     swap(a[start],a[end]); 
   } 
   else 
   { 
     t=a[end]; 
     a[end]=a[l]; 
     a[l]=t; 
     return end--; 
   } 
 } 
 return 0; 
} 

void quickSort(student *a[], int l, int u)  //QuickSort for sorting
{ 
 if (l< u) 
 { 
   int loc = partition(a, l, u); 
   quickSort(a, l, loc - 1); 
   quickSort(a, loc + 1, u); 
 } 
} 

void biSearch(student *a[],int l,int u, string k) //Binary Search
{ student *t=new student; 
 int i,mid,check=0; 
 while(l<=u) 
 { 
   mid=(u+l)/2; 
   if (a[mid]->name==k) 
   { 
     t=a[mid]; 
     check=1; 
     i=mid; 
     break; 
   } 
   else if(a[mid]->name<k) 
   { 
     l=mid+1; 
   } 
   else 
   { 
     u=mid-1; 
   } 
 } 
 if (check==0) 
 { 
   cout<<"NO MATCH FOUND"<<"\n"; 
 } 
 else 
 { 
   while(i >=0 && a[i]->name == a[mid]->name) 
   { 
     i--; 
   } 

   i++; 
   while(a[i]->name == a[mid]->name && i <= u) 
   { 
     cout<<a[i]->roll<<" "; 
     cout<<a[i]->name<<" "; 
     cout<<a[i]->sgpa<<"\n"; 
     i++; 
   } 
 } 
 
} 

void linSearch(student *a[],int u,float x)  //Linear Search 
{ int check=0; 
 for (int i=0;i<u;i++) 
 { 
   if(a[i]->sgpa==x) 
   { 
     cout<<a[i]->roll<<" "; 
     cout<<a[i]->name<<" "; 
     cout<<a[i]->sgpa<<"\n"; 
     check=1; 
   } 
 } 
 if(check==0) 
   cout<<"NO MATCH FOUND"<<"\n"; 
 
} 

int main() //main function
{ 
 int i=0,n,ch; 
 float m; 
 student *s[60]; 
 
 loop1: 
 cout<<"\n ENTER YOUR CHOICE: \n"; 
 cout<<"1. INSERT RECORDS: \n"; 
 cout<<"2. CLASS DETAILS(According to ROLL NO.) \n"; 
 cout<<"3. FIRST TEN TOPPERS OF THE CLASS \n"; 
 cout<<"4. CLASS DETAILS (IN ALPHABETICAL ORDER) \n"; 
 cout<<"5. FIND STUDENT (According to SGPA) \n"; 
 cout<<"6. FIND STUDENT (According to Name) \n"; 
 cin>>n; 
 if(n==1) 
 { 
   cout<<"ENTER DETAILS: \n"; 
   do 
   { 
     cout<<"STUDENT "<<i+1<<" RECORD:\n"; 
     s[i]=new student; 
     cout<<"Roll no :"; 
     cin>>s[i]->roll; 
     cout<<"Name: "; 
     cin>>s[i]->name; 
     cout<<"SGPA: "; 
     cin>>s[i]->sgpa; 

     cout<<"DO YOU WANT TO INPUT MORE RECORDS (enter 1 if yes) \n"; 
     cin>>ch; 
     i++; 

   } 
   while(ch==1); 
   goto loop1; 
 } 
 if(n==2) 
 { 
   cout<<"*****CLASS DETAILS(according to ROLL NO.)*****"<<"\n"<<"\n"; 
   bubSort(s,i); 
   show1(s,i); 
 } 
 else if(n==3) 
 { 
   cout<<"*****FIRST TEN TOPPERS*****"<<"\n"<<"\n"; 
   quickSort(s,0,i-1); 
   show2(s,i); 
 } 
 else if(n==4) 
 { 
   cout<<"*****CLASS DETAILS (IN ALPHABETICAL ORDER)*****"<<"\n"<<"\n"; 
   inserSort(s,i); 
   show1(s,i); 
 } 
 else if(n==5) 
 { 
   cout<<"*****FIND STUDENT (According to SGPA)*****"<<"\n"<<"ENTER SGPA"<<"\n"<<"\n"; 
   cin>>m; 
   linSearch(s,i,m); 
 } 
 else if(n==6) 
 { 
   cout<<"*****FIND STUDENT (According to Name)*****"<<"\n"<<"ENTER NAME"<<"\n"<<"\n"; 
   string nm; 
   cin>>nm; 
   inserSort(s,i); 
   biSearch(s,0,i,nm); 
 } 
 else 
 { 
   cout<<"INVALID INPUT!!\n"; 
 } 
 cout<<"WANT TO CONTINUE? (enter y or Y):\n"; 
 cin>>ch; 
 if(ch==1) 
 { 
   goto loop1; 
 } 
 return 0; 
}
