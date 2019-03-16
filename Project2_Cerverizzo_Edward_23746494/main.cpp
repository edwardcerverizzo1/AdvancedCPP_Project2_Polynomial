#include <iostream>
#include <fstream>
#include <TermClass.h> 
#include <polynomialClass.h>
#include <parser.h>

int main() {
  std::ifstream pf ("input.txt"); 
  std::string line1;
  std::string line2;

  if(pf.is_open()){
    std::getline(pf,line1);
    std::getline(pf,line2);
    std::cout <<"First polynomial:" << line1 <<std::endl;
    std::cout << std::endl;
    std::cout <<"Second polynomial:" <<line2 <<std::endl;  
    std::cout << std::endl;
  }else{
    std::cout<<"file is in use \n";
  }

  // CREATING POLYNOMIALS HERE
  Poly p1 = parser(line1);
  Poly p2 = parser(line2);
  
  pf.close();

  std::cout <<"First polynomial (reduced):" <<std::endl;
  p1.print();
  std::cout << std::endl;
  std::cout <<"Second polynomial (reduced):" <<std::endl;
  p2.print();
  std::cout << std::endl;

  std::cout<<"operator+ demo" <<std::endl;
  Poly p3 = p1+p2;
  p3.print();
  std::cout<<std::endl;

  std::cout<<"operator- demo" <<std::endl;
  Poly p4 = p1 - p2;
  p4.print();
  std::cout<<std::endl;

  std::cout<<"operator* demo" <<std::endl;
  Poly p5 = p1 * p2;
  p5.print();
  std::cout<<std::endl;


  std::ofstream of;
  of.open("output.txt");

  of << "First polynomial: " << line1 <<std::endl;
  of << "Second polynomial: " << line2 <<std::endl;
  of << "First polynomial (reduced): "<< std::endl;
  of << p1<< std::endl;
  of << "Second polynomial (reduced): " << std::endl;
  of << p2 << std::endl;
  of << "operator+ demo: " << std::endl;
  of << p3 << std::endl;
  of << "operator- demo: " << std::endl;
  of << p4 << std::endl;
  of << "operator* demo: " << std::endl;
  of << p5 << std::endl;
  
  of.close();



  /* // createAndInsert Demo
  std::cout<<"poly createAndInsert and print demo"<<std::endl;
  poly np;
  np.createAndInsert(3,5);
  np.createAndInsert(4,6);
  np.createAndInsert(7,8);
  np.print();
  */

  std::cout<< "done" <<std::endl;

}
