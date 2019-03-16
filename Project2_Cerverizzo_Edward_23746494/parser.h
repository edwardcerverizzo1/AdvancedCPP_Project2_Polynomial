/*
Notes: 
  Will not work with negitive exponets

How it works:
  Parser will break up string into substrings.
  The next term will begin at + or - and will assign ss1 (substring1) the substring from 0 until (that character - 1).

  You'll notice on line 19 we add either a + or a - to the end of the line string. This is nessicary to tell the parser where the end of he last term is.
*/

// Parse input string and create terms (nodes) for the Poly class
Poly parser(std::string line){

  int x,y,xl,yl,endOfTerm;;
  std::string ss1;
  int coff = 0; 
  int exp = 0; 
  bool exponetsTurn = false;
  bool isNegative = false;
  bool varriableExsists = false;
  Poly p; 

  xl=line.find_last_of('-');
  yl=line.find_last_of('+');

  if(xl<yl) // Last term is postive
    line+= '-';
  else  // Last term is negitive
    line+= '+';

  while(line.size() != 0){
    if(line.at(0) == '-'){
      //std::cout<<"found -, is negative is now true"<< std::endl;
      isNegative = true;
      line.erase(0,1);
    }
    else if(line.at(0) == '+'){
      //std::cout<<"found +, isNegative is now false"<< std::endl;
      isNegative = false;
      line.erase(0,1);
    }

    x= line.find_first_of('-');
    y = line.find_first_of('+');

    endOfTerm = (x < y) ? x : y;

    // Used for debugging -- Will be triggered when there are multiple '+' or '-'. e.g. ++3x^2
    if(x == 0 || y == 0)
      exit(3);

    ss1 = line.substr(0,endOfTerm);
    line.erase(0,endOfTerm);
      while(!ss1.empty()){
        if (ss1.at(0) >= '0' && ss1.at(0) <= '9'){
          if(!exponetsTurn){
            //std::cout<<"found a number (coff)"<< std::endl;
            coff = coff * 10;
            coff = coff + (((int) ss1.at(0)) - 48);
            //std::cout<< coff << std::endl;
          }
          else{
            //std::cout<<"found a number (exp)"<< std::endl;
            exp = exp * 10;
            exp  = exp + (((int) ss1.at(0)) - 48);
            //std::cout<< exp << std::endl;
          }
        }
        else if(ss1.at(0) == '^'){
          //std::cout<<"found ^" << std::endl;
          exponetsTurn = true;
        }
        else{
          //std::cout<<"found something else" << std::endl;
          varriableExsists = true;
          if(coff == 0){//if coff = 1, we have a hidden coff
            coff = 1;
            exponetsTurn = true;
          }
        }
        ss1.erase(0,1);
      }
    //std::cout<<"exiting while loop" << std::endl;

    // Modify parameters before creating term
      if(isNegative == true){
        coff = coff * -1;
        isNegative = false;
      }
      if(varriableExsists == true && exp == 0){
        exp = 1;
        varriableExsists = false; // Reset value only if used to minimize bus traffic 
      }
      
      // Create term in Poly class.
      p.createAndInsert(coff,exp);

      // Reset coff and exp -- Must always do
      coff = 0;
      exp = 0;
      exponetsTurn = false;
  }

return p;
}