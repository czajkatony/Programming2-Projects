/**
@Author: Tony Czajka 3010647
@File: City.cpp
@Date: 10/29/21
@Brief:This is the City.cpp class. It is the implementation of the City class which defines the methods described
in the header file. It is sued to move the blob around and change the array of the city accordingly.
**/

#include "City.h"

City::City(std::ifstream& inFile){
  totalEaten=0;
  isSewer=false;
  char temp;
  inFile >> rows >> cols>>m_start_x>>m_start_y;
  if(rows<1||cols<1){
	  throw(std::runtime_error("Invalid number of rows/columns."));
  }
  if(m_start_x<0||m_start_x>=rows||m_start_y<0||m_start_y>=cols){
	  throw(std::runtime_error("Invalid starting position."));
  }
  grid=new char*[rows];
  sewerGrid=new char*[rows];
  for(int i=0;i<cols; i++){
    grid[i]=new char[cols];
	sewerGrid[i]=new char[cols];
  }
  for(int i=0; i<rows;i++){
    for(int j=0;j<cols;j++){
      inFile>>temp;
      if(temp !='\n'){
        grid[i][j]=temp;
      }
      else{
        inFile>>temp;
        grid[i][j]=temp;
      }
	  if(temp=='@'){
		  sewerGrid[i][j]='X';
	  }
	  else{
		  sewerGrid[i][j]='O';
	  }
    }
  }
}

void City::blobbifyCity(){
//  std::cout<<"STARTPOS: "<<m_start_x<<"  "<<m_start_y<<'\n'; //DELETETHISLATER
  blobbify(m_start_x,m_start_y);
  if(isSewer){
    for(int i=0;i<rows;i++){
      for(int j=0; j<cols; j++){
        if(grid[i][j]=='@'&&sewerGrid[i][j]=='X'){
          blobbify(i,j);
        }
      }
    }
  }

}

void City::print(){
  if(grid[m_start_x][m_start_y]=='#'){
    throw(std::runtime_error("Invalid starting position. Tried to start on a wall ('#')\n"));
  }
  std::cout<<"Rows: "<<rows<<'\n'<<"Columns: "<<cols<<'\n';
  std::cout<<"Starting locaiton: ("<<m_start_x<<", "<<m_start_y<<")\n";
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      std::cout<<grid[i][j];
    }
    std::cout<<'\n';
  }
  std::cout<<'\n';
}

void City::mark(int x, int y){
  grid[x][y]='B';
//  std::cout<<"MARKED\n";
}


 void City::blobbify(int x, int y){
//   std::cout<<"GOTHERE\n";
   if(grid[x][y]=='S'||grid[x][y]=='P'||grid[x][y]=='@'){
    if(grid[x][y]=='P'){
       totalEaten++;
     }
    if(grid[x][y]=='P'||grid[x][y]=='S'){
       mark(x,y);
     }

     if(isValidMove(x-1,y)){
       blobbify(x-1,y);

     }
     if(isValidMove(x,y+1)){
  //     std::cout<<"VALIDMOVEWORKS\n";
       blobbify(x,y+1);
     }
     if(isValidMove(x+1,y)){
       blobbify(x+1,y);
     }
     if(isValidMove(x,y-1)){
       blobbify(x,y-1);
     }
	 if(grid[x][y]=='@'){
		isSewer=true;
		sewerGrid[x][y]='O';
	 }
   }
 }

 bool City::isValidMove(int x, int y){
   if(x<0||x>=rows||y<0||y>=cols){
     return(false);
   }
   else if(grid[x][y]=='#'){
     return(false);
   }
   else{
     return(true);
   }
 }

 int City::getPeopleEaten()const{
	 return(totalEaten);
 }


City::~City(){
  for(int i=0;i<rows;i++){
    delete[] grid[i];
	delete[] sewerGrid[i];
  }
  delete[] grid;
  delete[] sewerGrid;
}
