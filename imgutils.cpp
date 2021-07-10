#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Image {
  int mx;
  int my;
  int* points;
      //картинка размером mx * my
};



// Создание изображения
void createImage(Image* img,int tmx, int tmy) {
    img->points = new int[tmx*tmy]{0};
    img->mx=tmx;
    img->my=tmy;
    
    
}


// Отображения изображения на экран в pnm формате
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  1 0 0 0 1 0
//  0 1 1 1 0 0
//  0 0 0 0 0 0
//  0 0 0 0 0 0


void showImage(Image* img) {
    int transit = 0;
    for( int n =0; n < (img->mx*img->my);n++){
        if (transit != img->mx) {
            cout<<img->points[n];
            transit +=1;
        }
        else {
            
            cout<<img->points[n];
            cout<<"\n";
            transit = 0;
            //cout<<"tru";
            
        }
        
        
    }

}


// Изменения точки на изображения
//  Необходимо изменить в массиве points - точку с координатами mx*y+x в цвето color
//  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  1 0 0 0 1 0  0 1 1 1 0 0  0 0 0 0 0 0  0 0 0 0 0 0
   

void setPointImage(Image* img,int x, int y,int color) {
    img->points[img->mx*y+x] = color;
}


// Получение точки на изображение
int getPointImage(Image* img,int x, int y) {
  return img->points[img->mx*y+x];
  
}


// Отображения изображения на экран в pnm формате - P1
// https://en.wikipedia.org/wiki/Netpbm#File_formats
//
//  P1
//  6 10
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  1 0 0 0 1 0
//  0 1 1 1 0 0
//  0 0 0 0 0 0
//  0 0 0 0 0 0
//  Файл можно открыть в gimp

void saveToPnmFile(Image* img, string fileName) {
    
    ofstream fout;
    fout.open(fileName);
    
    int transit = 0;
    for( int n =0; n < (img->mx*img->my);n++){
        if (transit != img->mx-1) {
            fout<<img->points[n];
            transit +=1;
        }
        else {

            fout<<img->points[n];
            fout<<endl;
            transit = 0;
            
            
        }
    

    }
    
    fout.close();
}
    
    
    
int testCreateImage(){
        Image* img = new Image;
        createImage(img, 6, 10);
        if (img->mx != 6 || img->my != 10) return -1;
        for (int n =0; n<img->mx*img->my; n++){
            if (img->points[n] != 0) return -1;
            
        }
        
        return 0;
    }

int testShowImage(){
    
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img, 1, 1, 123);
    if (img->points[img->mx*1+1] != 123) return -1;
    return 0;
}

int testSetPointImage(){
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img,1,1,123);
    setPointImage(img,0,0,1);
    if (img->points[img->mx*1+1] != 123 || img->points[img->mx*0+0] != 1) return -1;
    return 0;
    
}




int testGetPointImage(){
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img,1,1,123);
    if(getPointImage(img, 1, 1) != 123) return -1;
    return 0;
    
}

int testSaveToPnmFile(){
    Image* img = new Image;
    createImage(img, 2, 2);
    saveToPnmFile(img, "testImg.pnm");
    
    fstream f;
    f.open("testImg.pnm",ios::in);
    long file_size;
    f.seekg(0, ios::end);
    file_size = f.tellg();
    if (file_size == 0) {
        f.close();
        return -1;
    }
    f.close();
    return 0;
    
}
    

static void runTest(int( * testFunction)(),
  const std::string & testName) {
  if (testFunction() == 0)
    std::cout << "Test " << testName << " - OK" << std::endl;
  else
    std::cout << "Test " << testName << " - FAIL" << std::endl;
}



const float g = 9.8;

struct Ball {
  float h = rand() % 20; // высота h
  float x = 0;
  float y = 0;
  float vx = rand() % 10; // скорость v
  float vy = 0;
  float ax = 0;
  float ay = -g;
  float m = 0;

  Ball() {}
};

float dt_full = 0;
float flightTime = 0;
void move(Ball * ball, float dt) {
  // по оси y

  dt_full += dt;;
  ball -> vy += (ball -> ay) * dt_full;
  ball -> y = ball -> h + ball -> ay * pow(dt_full, 2) / 2;

  //по оси x
  ball -> ax = 0;

  ball -> x += ball -> vx * dt;
  if (ball -> y > 0) flightTime = dt_full;
  if (ball -> y <= 0) { // "прилипает"
    ball -> y = 0;
    ball -> vy = 0;
    ball -> vx = 0;

  }

}

void show(Ball ball) {
  cout << "y= " << ball.y << " vy= " << abs(ball.vy) << " ay= " << abs(ball.ay) << endl;
  cout << "   x= " << ball.x << " vx= " << abs(ball.vx) << " ax= " << abs(ball.ax) << endl;
  cout << endl;

}

//--------------
struct Node {
  float val_vx, val_vy, val_ax, val_ay, t, val_x,val_y;
  Node * next;

};

void init(Node * node) {

  node -> next = NULL;

}

void showNode(Node * head) {

  while (head -> next != NULL) {

    cout << "t= " << head -> t << " vy = " << abs(head -> val_vy) << " ay =  " << abs(head -> val_ay) << endl;
    cout << "\t  vx = " << abs(head -> val_vx) << " ax = " << abs(head -> val_ax) << endl;
    head = head -> next;

  }
}

void pushNode(Node * head, Node * node) {

  while (head -> next != NULL)
    head = head -> next;

  head -> next = node;
  node -> next = NULL;

}



void save(Node * head, Node * head_node, float vx, float vy, float ax, float ay, float t) {

  pushNode(head, new Node);
  head_node -> val_ax = ax;

  head_node -> val_ay = ay;
  head_node -> val_vx = vx;
  head_node -> val_vy = vy;
  head_node -> t = t;

  head_node = head_node -> next;

}


void Reverse_Y(Image* img){
    
    
}


int DrawTraect() {
    Image* img = new Image;
  Ball a;
  float deltaT = 0.01;
  Node * head = new Node;
  Node * head_node = head;
  init(head);
  init(head_node);
  createImage(img, 250, 250);

  float t = 0;
  for (int i = 0; i < 250; i++) {

      if (i != 0){ move( & a, deltaT);
          setPointImage(img,int(a.x*10),int(a.y*10), 1);}
    pushNode(head, new Node);
      head_node -> val_x = a.x;
      head_node -> val_y = a.y;
    t += deltaT;
      
  }
    
        
        
        
    
    
    saveToPnmFile(img, "traect.pnm");
  return 0;
}


int main() {
    
    runTest(testCreateImage,"testCreateImage");
    runTest(testShowImage, "testShowImage");
    runTest(testSetPointImage, "testSetPointImage");
    runTest(testGetPointImage, "testGetPointImage");
    runTest(testSaveToPnmFile, "testSaveToPnmFile");
    cout <<endl<<endl;
    
    DrawTraect();
    
  return 0;
}
