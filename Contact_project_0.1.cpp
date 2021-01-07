/* MY name : Mohamed saif aldeen
     Class : Second Year
   Department : Computer Engineering
*/

#include<iostream>
#include<vector>
#include<fstream>

using namespace std  ;
class Contact {
  public :
   string Name ;
   string Given_Name;
   string Family_Name;
   string Gender;
   string Location ;
   string Language ;
   string Phone_1_Type;
   long Phone_1_Value ;
   // these two varibles to merge another phone number with same contact
   string Phone_2_Type=" none ";
   long Phone_2_Value=0;

   void print() {
     std::cout << "\nName:  "<<Name <<"\nGiven Name: "<< Given_Name <<"\nFamily Name: "<<Family_Name ;
     std::cout << "\nGender: "<<Gender <<"\nLocation: "<<Location<<"\nLanguage: "<<Language<<"\nPhone Type: "<<
      Phone_1_Type<<"\nPhone Value: "<< Phone_1_Value<<"\nPhone_2_Type: "<<Phone_2_Type<<"\nPhone_2 Value: "<<Phone_2_Value<<endl;
   }
   void print_to_file() {
   fstream fout ;
   fout.open("Contacts.ods", ios::out | ios::app);
     fout << "\nName:  "<<Name <<"\nGiven Name: "<< Given_Name <<"\nFamily Name: "<<Family_Name ;
     fout << "\nGender: "<<Gender <<"\nLocation: "<<Location<<"\nLanguage: "<<Language<<"\nPhone Type: "<<
      Phone_1_Type<<"\nPhone Value: "<< Phone_1_Value<<"\nPhone_2_Type: "<<Phone_2_Type<<"\nPhone_2 Value: "<<Phone_2_Value<<endl;
 }


} ;


int main() {
  vector<Contact>records ;
  int indx = -1 ;
  std::cout << " Choose what do you want: "<< '\n';
  std::cout << "1/search in fileds for records \n2/add record\n3/remove record\n4/edit record\n5/merge record\n6/print the Contacts\n7/print to file " << '\n';
  int n ;
  cin>>n;
  while (n != 0) {

    // search
    if (n==1)
    {
        std::cout << "Enter the record name you want to search in :" << '\n';
        string y ;
        cin >> y ;
        for(int i = 0 ; i<=indx; ++i) {
          if(records[i].Name == y) {
            std::cout << "Enter the filed you want : " << '\n';
            std::cout << "1/ Name \n2/ Given Name \n3/ Family Name \n4/ Gender \n5/ Location \n6/Language \n7/Phone Type \n8/Phone Value " << '\n';
            int g ;
            cin >> g ;
            if(g==1) {
              std::cout << records[i].Name << '\n';
            }
            if(g==2) {
              std::cout << records[i].Given_Name << '\n';
            }
            if(g==3) {
              std::cout << records[i].Family_Name << '\n';
            }
            if(g==4) {
              std::cout << records[i].Gender << '\n';
            }
            if(g==5) {
              std::cout << records[i].Location << '\n';
            }
            if(g==6) {
              std::cout << records[i].Language << '\n';
            }
            if(g==7)
            {
              std::cout << records[i].Phone_1_Type << '\n';
            }
            if(g==8)
            {
              std::cout << records[i].Phone_1_Value << '\n';
          }
        }

    }
  }
    // creat
    if (n==2)
    {
        Contact v ;
        std::cout << "Enter the data of te new contact : " << '\n';
          std::cout << "Enter the name  : " << '\n';
          cin >> v.Name  ;
        std::cout << "Enter the Given Name : " << '\n';
          cin >> v.Given_Name  ;
        std::cout << "Enter the Family Name : " << '\n';
          cin >> v.Family_Name  ;
        std::cout << "Enter the Gender : " << '\n';
          cin >> v.Gender  ;
        std::cout << "Enter the Location : " << '\n';
          cin >> v.Location  ;
        std::cout << "Enter the Language : " << '\n';
          cin >> v.Language  ;
        std::cout << "Enter the Phone Type : " << '\n';
          cin >> v.Phone_1_Type  ;
        std::cout << "Enter the Phone Value : " << '\n';
          cin >> v.Phone_1_Value  ;
        //v.print() ;
        records.push_back(v) ;
        ++indx ;

    }
    // remove
    if (n==3)
    {
        if(records.empty()) {
            std::cout << "Sorry there is no contacts" << '\n';}
        else {
            std::cout << "Enter the name of contact you want to remove : " << '\n';
            string s ;
            cin >>s ;
            for (int i=0; i<=indx ; ++i) {
                if(records[i].Name == s)
                    records.erase(records.begin()+i);
                  }
                  --indx ;
                }
              }
    // edit
    if (n==4)
    {
        std::cout << "What the name of contact do you want to edit : " << '\n';
        string s ;
        cin >> s ;
        for (int i=0; i<=indx ; ++i) {
          if(records[i].Name == s) {
            std::cout << "What the fields you want to edit: " << '\n';
            std::cout << "1/ Name \n2/ Given Name \n3/ Family Name \n4/ Gender \n5/ Location \n6/Language  7/Phone Type \n8/Phone Value " << '\n';
            int g ;
            cin >> g ;
            if(g==1) {
              std::cout << "Enter the new name you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Name = b ;
            }
            if(g==2) {
              std::cout << "Enter the new name you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Given_Name = b ;
            }
            if(g==3) {
              std::cout << "Enter the new Given Name you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Family_Name = b ;
            }
            if(g==4) {
              std::cout << "Enter the new Family Name you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Gender = b ;
            }
            if(g==5) {
              std::cout << "Enter the new Gender you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Location = b ;
            }
            if(g==6) {
              std::cout << "Enter the new Location you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Language = b ;
            }
            if(g==7)
            {
              std::cout << "Enter the new Phone Type you want to add " << '\n';
              string b ;
              cin>>b ;
              records[i].Phone_1_Type = b ;
            }
            if(g==8)
            {
              std::cout << "Enter the new Phone Value you want to add " << '\n';
              long b ;
              cin>>b ;
              records[i].Phone_1_Value = b ;
            }
          }
        }
    }
    // merge
    if (n==5)
    {
      std::cout << "The program will find any same contact Name and merge them "<<'\n' ;
      std::cout << "Wait ......." << '\n';
      for (int i=0 ; i<=indx -1; ++i) {
        if(records[i].Name == records[i+1].Name) {
          records[i].Phone_2_Type = records[i+1].Phone_1_Type ;
          records[i].Phone_2_Value = records[i+1].Phone_1_Value ;
          records.erase(records.begin()+(i+1)) ;
          --indx ;
          std::cout << "Done....." << '\n';
        }
        else
          std::cout << "No any same names in the contacts." << '\n';
      }

    }
    // print
    if(n==6) {
        for (int i=0; i<=indx ; ++i) {
            records[i].print() ;}
            //std::cout  << '\n';
    }

    // print to file
    if(n==7){
      for (int i=0; i<=indx ; ++i) {
          records[i].print_to_file() ;}
    }
    std::cout << "\n\n1/search in fileds for records \n2/add record\n3/remove record\n4/edit record\n5/merge record\n6/print the Contacts\n7/print to file " << '\n';
    std::cout << "IF you want to exit press 0 " << '\n';
    cin >> n ;

  }
  return 0;
}
