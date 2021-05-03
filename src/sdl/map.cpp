#include "map.h"



Map::Map(){

carte1=(int**)malloc(13*sizeof(int*));
for(int i=0;i<13;i++){
    carte1[i]=(int*)malloc(28*sizeof(int));
}

carte1[0][0]=1;  //0 = Vide 1= Mur 3=plant
carte1[0][1]=1;
carte1[0][2]=1;
carte1[0][3]=1;
carte1[0][4]=1;
carte1[0][5]=1;
carte1[0][6]=1;
carte1[0][7]=1;
carte1[0][8]=1;
carte1[0][9]=1;
carte1[0][10]=1;
carte1[0][11]=1;
carte1[0][12]=1;
carte1[0][13]=1;
carte1[0][14]=1;
carte1[0][15]=1;
carte1[0][16]=1;
carte1[0][17]=1;
carte1[0][18]=1;
carte1[0][19]=1;
carte1[0][20]=1;
carte1[0][21]=1;
carte1[0][22]=1;
carte1[0][23]=1;
carte1[0][24]=1;
carte1[0][25]=1;
carte1[0][26]=1;
carte1[0][27]=1;

carte1[1][0]=1;
carte1[1][1]=1;
carte1[1][2]=1;
carte1[1][3]=1;
carte1[1][4]=1;
carte1[1][5]=0;
carte1[1][6]=0;
carte1[1][7]=0;
carte1[1][8]=0;
carte1[1][9]=0;
carte1[1][10]=0;
carte1[1][11]=0;
carte1[1][12]=0;
carte1[1][13]=0;
carte1[1][14]=0;
carte1[1][15]=0;
carte1[1][16]=0;
carte1[1][17]=0;
carte1[1][18]=0;
carte1[1][19]=0;
carte1[1][20]=0;
carte1[1][21]=0;
carte1[1][22]=0;
carte1[1][23]=0;
carte1[1][24]=1;
carte1[1][25]=1;
carte1[1][26]=0;
carte1[1][27]=1;

carte1[2][0]=1;
carte1[2][1]=1;
carte1[2][2]=1;
carte1[2][3]=1;
carte1[2][4]=1;
carte1[2][5]=1;
carte1[2][6]=1;
carte1[2][7]=0;
carte1[2][8]=1;
carte1[2][9]=1;
carte1[2][10]=0;
carte1[2][11]=0;
carte1[2][12]=0;
carte1[2][13]=0;
carte1[2][14]=0;
carte1[2][15]=0;
carte1[2][16]=0;
carte1[2][17]=0;
carte1[2][18]=0;
carte1[2][19]=0;
carte1[2][20]=0;
carte1[2][21]=0;
carte1[2][22]=0;
carte1[2][23]=0;
carte1[2][24]=1;
carte1[2][25]=1;
carte1[2][26]=0;
carte1[2][27]=1;

carte1[3][0]=1;
carte1[3][1]=1;
carte1[3][2]=1;
carte1[3][3]=1;
carte1[3][4]=1;
carte1[3][5]=0;
carte1[3][6]=0;
carte1[3][7]=0;
carte1[3][8]=1;
carte1[3][9]=1;
carte1[3][10]=1;
carte1[3][11]=0;
carte1[3][12]=0;
carte1[3][13]=0;
carte1[3][14]=0;
carte1[3][15]=0;
carte1[3][16]=0;
carte1[3][17]=0;
carte1[3][18]=0;
carte1[3][19]=0;
carte1[3][20]=0;
carte1[3][21]=0;
carte1[3][22]=0;
carte1[3][23]=0;
carte1[3][24]=0;
carte1[3][25]=0;
carte1[3][26]=0;
carte1[3][27]=1;

carte1[4][0]=1;
carte1[4][1]=0;
carte1[4][2]=0;
carte1[4][3]=0;
carte1[4][4]=0;
carte1[4][5]=0;
carte1[4][6]=0;
carte1[4][7]=0;
carte1[4][8]=0;
carte1[4][9]=0;
carte1[4][10]=0;
carte1[4][11]=0;
carte1[4][12]=0;
carte1[4][13]=0;
carte1[4][14]=0;
carte1[4][15]=0;
carte1[4][16]=0;
carte1[4][17]=0;
carte1[4][18]=0;
carte1[4][19]=0;
carte1[4][20]=0;
carte1[4][21]=0;
carte1[4][22]=0;
carte1[4][23]=0;
carte1[4][24]=0;
carte1[4][25]=0;
carte1[4][26]=0;
carte1[4][27]=1;

carte1[5][0]=1;
carte1[5][1]=0;
carte1[5][2]=0;
carte1[5][3]=0;
carte1[5][4]=0;
carte1[5][5]=0;
carte1[5][6]=0;
carte1[5][7]=0;
carte1[5][8]=0;
carte1[5][9]=0;
carte1[5][10]=0;
carte1[5][11]=0;
carte1[5][12]=0;
carte1[5][13]=0;
carte1[5][14]=0;
carte1[5][15]=0;
carte1[5][16]=0;
carte1[5][17]=0;
carte1[5][18]=0;
carte1[5][19]=0;
carte1[5][20]=0;
carte1[5][21]=0;
carte1[5][22]=0;
carte1[5][23]=0;
carte1[5][24]=0;
carte1[5][25]=0;
carte1[5][26]=0;
carte1[5][27]=1;


carte1[6][0]=1;
carte1[6][1]=0;
carte1[6][2]=0;
carte1[6][3]=0;
carte1[6][4]=0;
carte1[6][5]=0;
carte1[6][6]=0;
carte1[6][7]=0;
carte1[6][8]=0;
carte1[6][9]=0;
carte1[6][10]=0;
carte1[6][11]=0;
carte1[6][12]=0;
carte1[6][13]=0;
carte1[6][14]=0;
carte1[6][15]=0;
carte1[6][16]=0;
carte1[6][17]=0;
carte1[6][18]=0;
carte1[6][19]=0;
carte1[6][20]=0;
carte1[6][21]=0;
carte1[6][22]=0;
carte1[6][23]=0;
carte1[6][24]=0;
carte1[6][25]=0;
carte1[6][26]=0;
carte1[6][27]=1;

carte1[7][0]=1;
carte1[7][1]=0;
carte1[7][2]=0;
carte1[7][3]=0;
carte1[7][4]=0;
carte1[7][5]=0;
carte1[7][6]=0;
carte1[7][7]=0;
carte1[7][8]=0;
carte1[7][9]=0;
carte1[7][10]=0;
carte1[7][11]=0;
carte1[7][12]=0;
carte1[7][13]=0;
carte1[7][14]=0;
carte1[7][15]=0;
carte1[7][16]=0;
carte1[7][17]=0;
carte1[7][18]=0;
carte1[7][19]=0;
carte1[7][20]=1;
carte1[7][21]=1;
carte1[7][22]=1;
carte1[7][23]=1;
carte1[7][24]=1;
carte1[7][25]=1;
carte1[7][26]=1;
carte1[7][27]=1;

carte1[8][0]=1;
carte1[8][1]=1;
carte1[8][2]=1;
carte1[8][3]=1;
carte1[8][4]=1;
carte1[8][5]=1;
carte1[8][6]=1;
carte1[8][7]=1;
carte1[8][8]=0;
carte1[8][9]=0;
carte1[8][10]=0;
carte1[8][11]=0;
carte1[8][12]=0;
carte1[8][13]=0;
carte1[8][14]=0;
carte1[8][15]=0;
carte1[8][16]=0;
carte1[8][17]=0;
carte1[8][18]=0;
carte1[8][19]=1;
carte1[8][20]=1;
carte1[8][21]=1;
carte1[8][22]=1;
carte1[8][23]=1;
carte1[8][24]=1;
carte1[8][25]=1;
carte1[8][26]=1;
carte1[8][27]=1;

carte1[9][0]=1;
carte1[9][1]=1;
carte1[9][2]=1;
carte1[9][3]=1;
carte1[9][4]=1;
carte1[9][5]=1;
carte1[9][6]=1;
carte1[9][7]=1;
carte1[9][8]=1;
carte1[9][9]=0;
carte1[9][10]=0;
carte1[9][11]=0;
carte1[9][12]=1;
carte1[9][13]=1;
carte1[9][14]=1;
carte1[9][15]=0;
carte1[9][16]=0;
carte1[9][17]=0;
carte1[9][18]=0;
carte1[9][19]=1;
carte1[9][20]=1;
carte1[9][21]=1;
carte1[9][22]=1;
carte1[9][23]=1;
carte1[9][24]=1;
carte1[9][25]=1;
carte1[9][26]=1;
carte1[9][27]=1;

carte1[10][0]=1;
carte1[10][1]=1;
carte1[10][2]=1;
carte1[10][3]=1;
carte1[10][4]=1;
carte1[10][5]=1;
carte1[10][6]=1;
carte1[10][7]=1;
carte1[10][8]=1;
carte1[10][9]=1;
carte1[10][10]=1;
carte1[10][11]=0;
carte1[10][12]=1;
carte1[10][13]=1;
carte1[10][14]=1;
carte1[10][15]=1;
carte1[10][16]=1;
carte1[10][17]=1;
carte1[10][18]=0;
carte1[10][19]=0;
carte1[10][20]=1;
carte1[10][21]=1;
carte1[10][22]=1;
carte1[10][23]=1;
carte1[10][24]=1;
carte1[10][25]=1;
carte1[10][26]=1;
carte1[10][27]=1;

carte1[11][0]=1;
carte1[11][1]=1;
carte1[11][2]=1;
carte1[11][3]=1;
carte1[11][4]=1;
carte1[11][5]=1;
carte1[11][6]=1;
carte1[11][7]=1;
carte1[11][8]=1;
carte1[11][9]=1;
carte1[11][10]=1;
carte1[11][11]=0;
carte1[11][12]=0;
carte1[11][13]=0;
carte1[11][14]=1;
carte1[11][15]=1;
carte1[11][16]=1;
carte1[11][17]=1;
carte1[11][18]=0;
carte1[11][19]=0;
carte1[11][20]=1;
carte1[11][21]=1;
carte1[11][22]=1;
carte1[11][23]=1;
carte1[11][24]=1;
carte1[11][25]=1;
carte1[11][26]=1;
carte1[11][27]=1;

carte1[12][0]=1;
carte1[12][1]=1;
carte1[12][2]=1;
carte1[12][3]=1;
carte1[12][4]=1;
carte1[12][5]=1;
carte1[12][6]=1;
carte1[12][7]=1;
carte1[12][8]=1;
carte1[12][9]=1;
carte1[12][10]=1;
carte1[12][11]=1;
carte1[12][12]=1;
carte1[12][13]=1;
carte1[12][14]=1;
carte1[12][15]=1;
carte1[12][16]=1;
carte1[12][17]=1;
carte1[12][18]=1;
carte1[12][19]=0;
carte1[12][20]=1;
carte1[12][21]=1;
carte1[12][22]=1;
carte1[12][23]=1;
carte1[12][24]=1;
carte1[12][25]=1;
carte1[12][26]=1;
carte1[12][27]=1;






carte2=(int**)malloc(13*sizeof(int*));
    for(int j=0;j<13;j++){
        carte2[j]=(int*)malloc(27*sizeof(int));
    }


carte2[0][5]=1;
carte2[0][6]=1;
carte2[0][7]=1;
carte2[0][8]=1;
carte2[0][9]=1;
carte2[0][10]=1;
carte2[0][11]=1;
carte2[0][12]=1;
carte2[0][13]=1;
carte2[0][14]=1;
carte2[0][15]=1;
carte2[0][16]=1;
carte2[0][17]=1;
carte2[0][18]=1;
carte2[0][19]=1;
carte2[0][20]=1;
carte2[0][21]=1;


carte2[1][5]=1;
carte2[1][6]=1;
carte2[1][7]=0;
carte2[1][8]=0;
carte2[1][9]=0;
carte2[1][10]=0;
carte2[1][11]=0;
carte2[1][12]=0;
carte2[1][13]=0;
carte2[1][14]=0;
carte2[1][15]=0;
carte2[1][16]=0;
carte2[1][17]=0;
carte2[1][18]=0;
carte2[1][19]=0;
carte2[1][20]=0;
carte2[1][21]=1;


carte2[2][5]=1;
carte2[2][6]=0;
carte2[2][7]=0;
carte2[2][8]=1;
carte2[2][9]=1;
carte2[2][10]=1;
carte2[2][11]=1;
carte2[2][12]=1;
carte2[2][13]=1;
carte2[2][14]=1;
carte2[2][15]=1;
carte2[2][16]=1;
carte2[2][17]=1;
carte2[2][18]=0;
carte2[2][19]=0;
carte2[2][20]=0;
carte2[2][21]=1;


carte2[3][5]=1;
carte2[3][6]=0;
carte2[3][7]=0;
carte2[3][8]=1;
carte2[3][9]=3;
carte2[3][10]=0;
carte2[3][11]=3;
carte2[3][12]=0;
carte2[3][13]=0;
carte2[3][14]=3;
carte2[3][15]=0;
carte2[3][16]=3;
carte2[3][17]=1;
carte2[3][18]=0;
carte2[3][19]=0;
carte2[3][20]=0;
carte2[3][21]=1;


carte2[4][5]=1;
carte2[4][6]=0;
carte2[4][7]=0;
carte2[4][8]=1;
carte2[4][9]=0;
carte2[4][10]=0;
carte2[4][11]=0;
carte2[4][12]=0;
carte2[4][13]=0;
carte2[4][14]=0;
carte2[4][15]=0;
carte2[4][16]=0;
carte2[4][17]=1;
carte2[4][18]=0;
carte2[4][19]=0;
carte2[4][20]=0;
carte2[4][21]=1;


carte2[5][5]=1;
carte2[5][6]=0;
carte2[5][7]=0;
carte2[5][8]=1;
carte2[5][9]=3;
carte2[5][10]=0;
carte2[5][11]=3;
carte2[5][12]=0;
carte2[5][13]=0;
carte2[5][14]=3;
carte2[5][15]=0;
carte2[5][16]=3;
carte2[5][17]=1;
carte2[5][18]=0;
carte2[5][19]=0;
carte2[5][20]=0;
carte2[5][21]=1;


carte2[6][5]=1;
carte2[6][6]=0;
carte2[6][7]=0;
carte2[6][8]=1;
carte2[6][9]=0;
carte2[6][10]=0;
carte2[6][11]=0;
carte2[6][12]=0;
carte2[6][13]=0;
carte2[6][14]=0;
carte2[6][15]=0;
carte2[6][16]=0;
carte2[6][17]=1;
carte2[6][18]=0;
carte2[6][19]=0;
carte2[6][20]=0;
carte2[6][21]=1;


carte2[7][5]=1;
carte2[7][6]=0;
carte2[7][7]=0;
carte2[7][8]=1;
carte2[7][9]=3;
carte2[7][10]=0;
carte2[7][11]=3;
carte2[7][12]=0;
carte2[7][13]=0;
carte2[7][14]=3;
carte2[7][15]=0;
carte2[7][16]=3;
carte2[7][17]=1;
carte2[7][18]=0;
carte2[7][19]=0;
carte2[7][20]=1;
carte2[7][21]=1;



carte2[8][5]=1;
carte2[8][6]=0;
carte2[8][7]=0;
carte2[8][8]=1;
carte2[8][9]=0;
carte2[8][10]=0;
carte2[8][11]=0;
carte2[8][12]=0;
carte2[8][13]=0;
carte2[8][14]=0;
carte2[8][15]=0;
carte2[8][16]=0;
carte2[8][17]=1;
carte2[8][18]=0;
carte2[8][19]=0;
carte2[8][20]=0;
carte2[8][21]=1;


carte2[9][5]=1;
carte2[9][6]=0;
carte2[9][7]=0;
carte2[9][8]=1;
carte2[9][9]=1;
carte2[9][10]=1;
carte2[9][11]=0;
carte2[9][12]=0;
carte2[9][13]=0;
carte2[9][14]=0;
carte2[9][15]=1;
carte2[9][16]=1;
carte2[9][17]=1;
carte2[9][18]=0;
carte2[9][19]=0;
carte2[9][20]=0;
carte2[9][21]=1;




carte2[10][5]=1;
carte2[10][6]=0;
carte2[10][7]=0;
carte2[10][8]=0;
carte2[10][9]=0;
carte2[10][10]=0;
carte2[10][11]=0;
carte2[10][12]=0;
carte2[10][13]=0;
carte2[10][14]=0;
carte2[10][15]=0;
carte2[10][16]=0;
carte2[10][17]=0;
carte2[10][18]=0;
carte2[10][19]=0;
carte2[10][20]=1;
carte2[10][21]=1;


carte2[11][5]=1;
carte2[11][6]=0;
carte2[11][7]=0;
carte2[11][8]=0;
carte2[11][9]=0;
carte2[11][10]=0;
carte2[11][11]=0;
carte2[11][12]=0;
carte2[11][13]=0;
carte2[11][14]=0;
carte2[11][15]=0;
carte2[11][16]=0;
carte2[11][17]=0;
carte2[11][18]=0;
carte2[11][19]=0;
carte2[11][20]=1;
carte2[11][21]=1;


carte2[12][5]=1;
carte2[12][6]=1;
carte2[12][7]=1;
carte2[12][8]=1;
carte2[12][9]=1;
carte2[12][10]=1;
carte2[12][11]=1;
carte2[12][12]=1;
carte2[12][13]=1;
carte2[12][14]=1;
carte2[12][15]=1;
carte2[12][16]=1;
carte2[12][17]=1;
carte2[12][18]=1;
carte2[12][19]=1;
carte2[12][20]=1;
carte2[12][21]=1;


carte3=(int**)malloc(13*sizeof(int*));
    for(int k=0;k<13;k++){
        carte3[k]=(int*)malloc(27*sizeof(int));
    }


carte3[0][5]=1;
carte3[0][6]=1;
carte3[0][7]=1;
carte3[0][8]=1;
carte3[0][9]=1;
carte3[0][10]=1;
carte3[0][11]=1;
carte3[0][12]=1;
carte3[0][13]=1;
carte3[0][14]=1;
carte3[0][15]=1;
carte3[0][16]=1;
carte3[0][17]=1;
carte3[0][18]=1;
carte3[0][19]=1;
carte3[0][20]=1;
carte3[0][21]=1;


carte3[1][5]=1;
carte3[1][6]=1;
carte3[1][7]=1;
carte3[1][8]=1;
carte3[1][9]=1;
carte3[1][10]=1;
carte3[1][11]=1;
carte3[1][12]=1;
carte3[1][13]=1;
carte3[1][14]=1;
carte3[1][15]=1;
carte3[1][16]=1;
carte3[1][17]=1;
carte3[1][18]=1;
carte3[1][19]=1;
carte3[1][20]=1;
carte3[1][21]=1;


carte3[2][5]=1;
carte3[2][6]=1;
carte3[2][7]=1;
carte3[2][8]=1;
carte3[2][9]=1;
carte3[2][10]=1;
carte3[2][11]=1;
carte3[2][12]=1;
carte3[2][13]=1;
carte3[2][14]=0;
carte3[2][15]=0;
carte3[2][16]=0;
carte3[2][17]=1;
carte3[2][18]=1;
carte3[2][19]=1;
carte3[2][20]=0;
carte3[2][21]=1;


carte3[3][5]=1;
carte3[3][6]=0;
carte3[3][7]=0;
carte3[3][8]=1;
carte3[3][9]=0;
carte3[3][10]=0;
carte3[3][11]=0;
carte3[3][12]=0;
carte3[3][13]=1;
carte3[3][14]=1;
carte3[3][15]=1;
carte3[3][16]=1;
carte3[3][17]=0;
carte3[3][18]=0;
carte3[3][19]=1;
carte3[3][20]=0;
carte3[3][21]=1;


carte3[4][5]=1;
carte3[4][6]=0;
carte3[4][7]=0;
carte3[4][8]=1;
carte3[4][9]=1;
carte3[4][10]=0;
carte3[4][11]=0;
carte3[4][12]=0;
carte3[4][13]=0;
carte3[4][14]=0;
carte3[4][15]=0;
carte3[4][16]=0;
carte3[4][17]=0;
carte3[4][18]=0;
carte3[4][19]=1;
carte3[4][20]=0;
carte3[4][21]=1;


carte3[5][5]=1;
carte3[5][6]=0;
carte3[5][7]=0;
carte3[5][8]=1;
carte3[5][9]=1;
carte3[5][10]=0;
carte3[5][11]=0;
carte3[5][12]=0;
carte3[5][13]=0;
carte3[5][14]=0;
carte3[5][15]=0;
carte3[5][16]=0;
carte3[5][17]=0;
carte3[5][18]=1;
carte3[5][19]=1;
carte3[5][20]=0;
carte3[5][21]=1;


carte3[6][5]=1;
carte3[6][6]=0;
carte3[6][7]=0;
carte3[6][8]=1;
carte3[6][9]=1;
carte3[6][10]=1;
carte3[6][11]=1;
carte3[6][12]=1;
carte3[6][13]=1;
carte3[6][14]=0;
carte3[6][15]=0;
carte3[6][16]=0;
carte3[6][17]=0;
carte3[6][18]=1;
carte3[6][19]=1;
carte3[6][20]=0;
carte3[6][21]=1;


carte3[7][5]=1;
carte3[7][6]=0;
carte3[7][7]=0;
carte3[7][8]=1;
carte3[7][9]=1;
carte3[7][10]=1;
carte3[7][11]=1;
carte3[7][12]=1;
carte3[7][13]=1;
carte3[7][14]=0;
carte3[7][15]=0;
carte3[7][16]=0;
carte3[7][17]=0;
carte3[7][18]=0;
carte3[7][19]=1;
carte3[7][20]=0;
carte3[7][21]=1;



carte3[8][5]=1;
carte3[8][6]=0;
carte3[8][7]=0;
carte3[8][8]=1;
carte3[8][9]=0;
carte3[8][10]=0;
carte3[8][11]=0;
carte3[8][12]=0;
carte3[8][13]=0;
carte3[8][14]=0;
carte3[8][15]=0;
carte3[8][16]=0;
carte3[8][17]=0;
carte3[8][18]=0;
carte3[8][19]=1;
carte3[8][20]=0;
carte3[8][21]=1;


carte3[9][5]=1;
carte3[9][6]=0;
carte3[9][7]=0;
carte3[9][8]=1;
carte3[9][9]=1;
carte3[9][10]=1;
carte3[9][11]=1;
carte3[9][12]=1;
carte3[9][13]=1;
carte3[9][14]=1;
carte3[9][15]=0;
carte3[9][16]=0;
carte3[9][17]=0;
carte3[9][18]=0;
carte3[9][19]=1;
carte3[9][20]=0;
carte3[9][21]=1;




carte3[10][5]=1;
carte3[10][6]=0;
carte3[10][7]=0;
carte3[10][8]=1;
carte3[10][9]=0;
carte3[10][10]=0;
carte3[10][11]=0;
carte3[10][12]=0;
carte3[10][13]=0;
carte3[10][14]=0;
carte3[10][15]=0;
carte3[10][16]=0;
carte3[10][17]=0;
carte3[10][18]=0;
carte3[10][19]=1;
carte3[10][20]=0;
carte3[10][21]=1;


carte3[11][5]=1;
carte3[11][6]=0;
carte3[11][7]=0;
carte3[11][8]=1;
carte3[11][9]=0;
carte3[11][10]=0;
carte3[11][11]=0;
carte3[11][12]=0;
carte3[11][13]=0;
carte3[11][14]=0;
carte3[11][15]=0;
carte3[11][16]=0;
carte3[11][17]=0;
carte3[11][18]=0;
carte3[11][19]=1;
carte3[11][20]=1;
carte3[11][21]=1;


carte3[12][5]=1;
carte3[12][6]=1;
carte3[12][7]=1;
carte3[12][8]=1;
carte3[12][9]=1;
carte3[12][10]=1;
carte3[12][11]=1;
carte3[12][12]=1;
carte3[12][13]=1;
carte3[12][14]=1;
carte3[12][15]=1;
carte3[12][16]=1;
carte3[12][17]=1;
carte3[12][18]=1;
carte3[12][19]=1;
carte3[12][20]=1;
carte3[12][21]=1;



carte4 = (int**)malloc(13*sizeof(int*));
    for(int m=0;m<13;m++){
        carte4[m]=(int*)malloc(27*sizeof(int));
    }


carte4[0][5]=1;
carte4[0][6]=1;
carte4[0][7]=1;
carte4[0][8]=1;
carte4[0][9]=1;
carte4[0][10]=1;
carte4[0][11]=1;
carte4[0][12]=1;
carte4[0][13]=1;
carte4[0][14]=1;
carte4[0][15]=1;
carte4[0][16]=1;
carte4[0][17]=1;
carte4[0][18]=1;
carte4[0][19]=1;
carte4[0][20]=1;
carte4[0][21]=1;


carte4[1][5]=1;
carte4[1][6]=1;
carte4[1][7]=1;
carte4[1][8]=1;
carte4[1][9]=1;
carte4[1][10]=1;
carte4[1][11]=1;
carte4[1][12]=1;
carte4[1][13]=1;
carte4[1][14]=1;
carte4[1][15]=1;
carte4[1][16]=1;
carte4[1][17]=1;
carte4[1][18]=1;
carte4[1][19]=1;
carte4[1][20]=1;
carte4[1][21]=1;


carte4[2][5]=1;
carte4[2][6]=1;
carte4[2][7]=1;
carte4[2][8]=1;
carte4[2][9]=1;
carte4[2][10]=0;
carte4[2][11]=0;
carte4[2][12]=1;
carte4[2][13]=0;
carte4[2][14]=0;
carte4[2][15]=1;
carte4[2][16]=1;
carte4[2][17]=1;
carte4[2][18]=1;
carte4[2][19]=1;
carte4[2][20]=0;
carte4[2][21]=1;


carte4[3][5]=1;
carte4[3][6]=0;
carte4[3][7]=1;
carte4[3][8]=1;
carte4[3][9]=1;
carte4[3][10]=1; //coffre
carte4[3][11]=1;
carte4[3][12]=1;
carte4[3][13]=0;
carte4[3][14]=0;
carte4[3][15]=1;
carte4[3][16]=0;
carte4[3][17]=0;
carte4[3][18]=0;
carte4[3][19]=1;
carte4[3][20]=0;
carte4[3][21]=1;


carte4[4][5]=1;
carte4[4][6]=0;
carte4[4][7]=1;
carte4[4][8]=1;
carte4[4][9]=0;
carte4[4][10]=0;
carte4[4][11]=1;
carte4[4][12]=1;
carte4[4][13]=1;
carte4[4][14]=1;
carte4[4][15]=1;
carte4[4][16]=0;
carte4[4][17]=0;
carte4[4][18]=1;
carte4[4][19]=1;
carte4[4][20]=0;
carte4[4][21]=1;


carte4[5][5]=1;
carte4[5][6]=0;
carte4[5][7]=1;
carte4[5][8]=0;
carte4[5][9]=0;
carte4[5][10]=0;
carte4[5][11]=0; 
carte4[5][12]=1;
carte4[5][13]=0;
carte4[5][14]=0;
carte4[5][15]=1;
carte4[5][16]=0;
carte4[5][17]=0;
carte4[5][18]=0;
carte4[5][19]=1;
carte4[5][20]=0;
carte4[5][21]=1;


carte4[6][5]=1;
carte4[6][6]=0;
carte4[6][7]=1;
carte4[6][8]=0;
carte4[6][9]=0;
carte4[6][10]=0;
carte4[6][11]=0;
carte4[6][12]=1;
carte4[6][13]=0;
carte4[6][14]=0;
carte4[6][15]=1;
carte4[6][16]=0;
carte4[6][17]=0;
carte4[6][18]=0;
carte4[6][19]=1;
carte4[6][20]=0;
carte4[6][21]=1;


carte4[7][5]=1;
carte4[7][6]=0;
carte4[7][7]=1;
carte4[7][8]=1;
carte4[7][9]=1;
carte4[7][10]=1;
carte4[7][11]=0; //echelle
carte4[7][12]=1;
carte4[7][13]=0;
carte4[7][14]=0;
carte4[7][15]=1;
carte4[7][16]=0;
carte4[7][17]=0;
carte4[7][18]=1;
carte4[7][19]=1;
carte4[7][20]=0;
carte4[7][21]=1;



carte4[8][5]=1;
carte4[8][6]=0;
carte4[8][7]=1;
carte4[8][8]=0;
carte4[8][9]=0;
carte4[8][10]=0;
carte4[8][11]=0;
carte4[8][12]=0;
carte4[8][13]=0;
carte4[8][14]=0;
carte4[8][15]=1;
carte4[8][16]=0;
carte4[8][17]=1;
carte4[8][18]=1;
carte4[8][19]=1;
carte4[8][20]=0;
carte4[8][21]=1;


carte4[9][5]=1;
carte4[9][6]=0;
carte4[9][7]=1;
carte4[9][8]=0;
carte4[9][9]=0;
carte4[9][10]=1;
carte4[9][11]=1;
carte4[9][12]=0;
carte4[9][13]=0;
carte4[9][14]=0;
carte4[9][15]=0;
carte4[9][16]=0;
carte4[9][17]=1;
carte4[9][18]=1;
carte4[9][19]=1;
carte4[9][20]=0;
carte4[9][21]=1;




carte4[10][5]=1;
carte4[10][6]=0;
carte4[10][7]=1;
carte4[10][8]=0;
carte4[10][9]=0;
carte4[10][10]=0;
carte4[10][11]=0;
carte4[10][12]=0;
carte4[10][13]=0;
carte4[10][14]=0;
carte4[10][15]=1;
carte4[10][16]=1;
carte4[10][17]=1;
carte4[10][18]=1;
carte4[10][19]=1;
carte4[10][20]=0;
carte4[10][21]=1;


carte4[11][5]=1;
carte4[11][6]=1;
carte4[11][7]=1;
carte4[11][8]=1;
carte4[11][9]=1;
carte4[11][10]=1;
carte4[11][11]=1;
carte4[11][12]=1;
carte4[11][13]=1;
carte4[11][14]=1;
carte4[11][15]=1;
carte4[11][16]=1;
carte4[11][17]=1;
carte4[11][18]=1;
carte4[11][19]=1;
carte4[11][20]=1;
carte4[11][21]=1;



carte5 = (int**)malloc(13*sizeof(int*));
    for(int n=0;n<13;n++){
        carte5[n]=(int*)malloc(27*sizeof(int));
    }


carte5[0][5]=1;
carte5[0][6]=1;
carte5[0][7]=1;
carte5[0][8]=1;
carte5[0][9]=1;
carte5[0][10]=1;
carte5[0][11]=1;
carte5[0][12]=1;
carte5[0][13]=1;
carte5[0][14]=1;
carte5[0][15]=1;
carte5[0][16]=1;
carte5[0][17]=1;
carte5[0][18]=1;
carte5[0][19]=1;
carte5[0][20]=1;
carte5[0][21]=1;


carte5[1][5]=1;
carte5[1][6]=1;
carte5[1][7]=1;
carte5[1][8]=1;
carte5[1][9]=1;
carte5[1][10]=1;
carte5[1][11]=1;
carte5[1][12]=0;
carte5[1][13]=0;
carte5[1][14]=0;
carte5[1][15]=1;
carte5[1][16]=1;
carte5[1][17]=1;
carte5[1][18]=1;
carte5[1][19]=1;
carte5[1][20]=1;
carte5[1][21]=1;


carte5[2][5]=1;
carte5[2][6]=1;
carte5[2][7]=1;
carte5[2][8]=1;
carte5[2][9]=1;
carte5[2][10]=1;
carte5[2][11]=1;
carte5[2][12]=0;
carte5[2][13]=0;
carte5[2][14]=0;
carte5[2][15]=1;
carte5[2][16]=1;
carte5[2][17]=1;
carte5[2][18]=1;
carte5[2][19]=1;
carte5[2][20]=1;
carte5[2][21]=1;


carte5[3][5]=1;
carte5[3][6]=1;
carte5[3][7]=1;
carte5[3][8]=1;
carte5[3][9]=1;
carte5[3][10]=1; 
carte5[3][11]=1;
carte5[3][12]=0;
carte5[3][13]=0;
carte5[3][14]=1;
carte5[3][15]=1;
carte5[3][16]=1;
carte5[3][17]=0;
carte5[3][18]=0;
carte5[3][19]=1;
carte5[3][20]=1;
carte5[3][21]=1;


carte5[4][5]=1;
carte5[4][6]=1;
carte5[4][7]=0;
carte5[4][8]=0;
carte5[4][9]=0;
carte5[4][10]=1;
carte5[4][11]=1;
carte5[4][12]=0;
carte5[4][13]=0;
carte5[4][14]=1;
carte5[4][15]=0; //PNJ n°1
carte5[4][16]=0; 
carte5[4][17]=0;
carte5[4][18]=0;
carte5[4][19]=1;
carte5[4][20]=1;
carte5[4][21]=1;


carte5[5][5]=1;
carte5[5][6]=1;
carte5[5][7]=0;
carte5[5][8]=0;
carte5[5][9]=0;
carte5[5][10]=0; //PNJ n°2
carte5[5][11]=0;  
carte5[5][12]=0;
carte5[5][13]=0;
carte5[5][14]=1;
carte5[5][15]=1;
carte5[5][16]=0;
carte5[5][17]=0;
carte5[5][18]=0;
carte5[5][19]=0;
carte5[5][20]=1;
carte5[5][21]=1;


carte5[6][5]=1;
carte5[6][6]=0;
carte5[6][7]=0;
carte5[6][8]=0;
carte5[6][9]=0;
carte5[6][10]=0; //PNJ n°2
carte5[6][11]=0;
carte5[6][12]=0;
carte5[6][13]=0;
carte5[6][14]=1;
carte5[6][15]=1;
carte5[6][16]=0;
carte5[6][17]=0;
carte5[6][18]=0;
carte5[6][19]=0;
carte5[6][20]=1;
carte5[6][21]=1;


carte5[7][5]=1;
carte5[7][6]=1;
carte5[7][7]=1;
carte5[7][8]=1;
carte5[7][9]=1;
carte5[7][10]=1;
carte5[7][11]=0; 
carte5[7][12]=0;
carte5[7][13]=0;
carte5[7][14]=1;
carte5[7][15]=1;
carte5[7][16]=1;
carte5[7][17]=0;
carte5[7][18]=1;
carte5[7][19]=1;
carte5[7][20]=1;
carte5[7][21]=1;



carte5[8][5]=1;
carte5[8][6]=0;
carte5[8][7]=0;
carte5[8][8]=0;
carte5[8][9]=0; //PNJ n°3
carte5[8][10]=0; 
carte5[8][11]=0;
carte5[8][12]=0;
carte5[8][13]=0;
carte5[8][14]=1;
carte5[8][15]=1;
carte5[8][16]=1;
carte5[8][17]=0;
carte5[8][18]=0;
carte5[8][19]=0;
carte5[8][20]=1;
carte5[8][21]=1;


carte5[9][5]=1;
carte5[9][6]=0;
carte5[9][7]=1;
carte5[9][8]=1;
carte5[9][9]=1;
carte5[9][10]=0;
carte5[9][11]=0;
carte5[9][12]=0;
carte5[9][13]=0;
carte5[9][14]=0;
carte5[9][15]=0; //PNJ n°4
carte5[9][16]=0;
carte5[9][17]=0;
carte5[9][18]=0;
carte5[9][19]=0;
carte5[9][20]=0;
carte5[9][21]=1;




carte5[10][5]=1;
carte5[10][6]=0;
carte5[10][7]=1;
carte5[10][8]=1;
carte5[10][9]=1;
carte5[10][10]=0;
carte5[10][11]=0;
carte5[10][12]=0;
carte5[10][13]=0;
carte5[10][14]=0;
carte5[10][15]=0; //PNJ n°4
carte5[10][16]=0;
carte5[10][17]=0;
carte5[10][18]=0;
carte5[10][19]=0;
carte5[10][20]=0;
carte5[10][21]=1;


carte5[11][5]=1;
carte5[11][6]=0;
carte5[11][7]=0;
carte5[11][8]=0;
carte5[11][9]=0;
carte5[11][10]=0;
carte5[11][11]=1;
carte5[11][12]=1;
carte5[11][13]=0;
carte5[11][14]=0;
carte5[11][15]=0;
carte5[11][16]=0;
carte5[11][17]=0;
carte5[11][18]=0;
carte5[11][19]=0;
carte5[11][20]=0;
carte5[11][21]=1;


carte5[12][5]=1;
carte5[12][6]=1;
carte5[12][7]=1;
carte5[12][8]=1;
carte5[12][9]=1;
carte5[12][10]=1;
carte5[12][11]=1;
carte5[12][12]=1;
carte5[12][13]=1;
carte5[12][14]=1;
carte5[12][15]=1;
carte5[12][16]=1;
carte5[12][17]=1;
carte5[12][18]=1;
carte5[12][19]=1;
carte5[12][20]=1;
carte5[12][21]=1;


interfaceJardin=(int**)malloc(12*sizeof(int*));
for( int p =0;p<13;p++){
    interfaceJardin[p]=(int*)malloc(27*sizeof(int));
}



interfaceJardin[4][9] = 12;
interfaceJardin[4][11] = 4;
interfaceJardin[4][13] = 8;
interfaceJardin[4][15] = 13;
interfaceJardin[4][17] = 17;
interfaceJardin[4][19] = 21;

interfaceJardin[6][9] = 1;
interfaceJardin[6][11] = 5;
interfaceJardin[6][13] = 9;
interfaceJardin[6][15] = 14;
interfaceJardin[6][17] = 18;
interfaceJardin[6][19] = 22;

interfaceJardin[7][9] = 2;
interfaceJardin[7][11] = 6;
interfaceJardin[7][13] = 10;
interfaceJardin[7][15] = 15;
interfaceJardin[7][17] = 19;
interfaceJardin[7][19] = 23;

interfaceJardin[9][9] = 3;
interfaceJardin[9][11] = 7;
interfaceJardin[9][13] = 11;
interfaceJardin[9][15] = 16;
interfaceJardin[9][17] = 20;
interfaceJardin[9][18] = 24;

interfaceInventaire=(int**)malloc(12*sizeof(int*));
for( int q =0;q<13;q++){
    interfaceInventaire[q]=(int*)malloc(27*sizeof(int));
}

interfaceInventaire[2][11] = 5;
interfaceInventaire[2][12] = 5;
interfaceInventaire[2][13] = 5;

interfaceInventaire[3][11] = 5;
interfaceInventaire[3][12] = 5;
interfaceInventaire[3][13] = 5;


interfaceInventaire[4][11] = 5;
interfaceInventaire[4][12] = 5;
interfaceInventaire[4][13] = 5;



interfaceInventaire[5][15] = 1;
interfaceInventaire[5][17] = 1;
interfaceInventaire[5][18] = 1;
interfaceInventaire[5][20] = 1;


interfaceInventaire[6][7] = 1;
interfaceInventaire[6][8] = 1;
interfaceInventaire[6][9] = 1;
interfaceInventaire[6][10] = 1;
interfaceInventaire[6][12] = 1;
interfaceInventaire[6][13] = 1;
interfaceInventaire[6][15] = 1;
interfaceInventaire[6][17] = 1;
interfaceInventaire[6][18] = 1;
interfaceInventaire[6][20] = 1;

interfaceInventaire[7][7] = 1;
interfaceInventaire[7][8] = 1;
interfaceInventaire[7][9] = 1;
interfaceInventaire[7][10] = 1;
interfaceInventaire[7][12] = 1;
interfaceInventaire[7][13] = 1;
interfaceInventaire[7][15] = 1;
interfaceInventaire[7][17] = 1;
interfaceInventaire[7][18] = 1;
interfaceInventaire[7][20] = 1;

interfaceInventaire[8][7] = 1;
interfaceInventaire[8][8] = 1;
interfaceInventaire[8][9] = 1;
interfaceInventaire[8][10] = 1;
interfaceInventaire[8][12] = 1;
interfaceInventaire[8][13] = 1;
interfaceInventaire[8][15] = 1;
interfaceInventaire[8][17] = 1;
interfaceInventaire[8][18] = 1;
interfaceInventaire[8][20] = 1;


interfaceInventaire[9][7] = 1;
interfaceInventaire[9][8] = 1;
interfaceInventaire[9][9] = 1;
interfaceInventaire[9][10] = 1;
interfaceInventaire[9][12] = 1;
interfaceInventaire[9][13] = 1;
interfaceInventaire[9][15] = 1;
interfaceInventaire[9][17] = 1;
interfaceInventaire[9][18] = 1;
interfaceInventaire[9][20] = 1;


interfaceInventaire[11][7] = 1;
interfaceInventaire[11][8] = 1;
interfaceInventaire[11][9] = 1;
interfaceInventaire[11][10] = 1;
interfaceInventaire[11][12] = 1;
interfaceInventaire[11][13] = 1;
interfaceInventaire[11][15] = 1;
interfaceInventaire[11][17] = 1;
interfaceInventaire[11][18] = 1;
interfaceInventaire[11][20] = 1;



carte10=(int**)malloc(13*sizeof(int*));
for(int j=0;j<13;j++){
    carte10[j]=(int*)malloc(28*sizeof(int));
    
}

for(int i = 0; i<28;i++){
    for(int j=0;j<13;j++){
        carte10[j][i] = 1;
    }
}


for(int i = 6;i <20;i++){
    for(int j=6; j<9;j++){
        carte10[j][i] = 6;
    }
}


carte10[9][11] = 0;
carte10[9][12] = 0;

carte10[10][11] = 0;
carte10[10][12] = 0;

carte10[11][11] = 0;
carte10[11][12] = 0;

carte10[12][11] = 0;
carte10[12][12] = 0;



carte11=(int**)malloc(13*sizeof(int*));
for(int j=0;j<13;j++){
    carte11[j]=(int*)malloc(28*sizeof(int));
    
}

for(int i = 0; i<28;i++){
    for(int j=0;j<13;j++){
        carte11[j][i] = 0;
    }
}

for(int i = 4; i<24;i++){
    carte11[0][i] = 4;
}

for(int i = 4; i<24;i++){
    carte11[12][i] = 1;
}

for(int j = 0; j<13;j++){
    carte11[j][3] = 1;
}

for(int j = 0; j<13;j++){
    carte11[j][24] = 1;
}









}


Map::~Map(){
    free(carte1);
    carte1 = NULL;
    free(carte2);
    carte2 = NULL;
    free(carte3);
    carte3 = NULL;
    free(carte4);
    carte4 = NULL;
    free(carte5);
    carte5 = NULL;
    free(interfaceJardin);
    interfaceJardin = NULL;
    free(interfaceInventaire);
    interfaceInventaire = NULL;
    free(carte10);
    carte10 = NULL;
    free(carte11);
    carte11 = NULL;
}