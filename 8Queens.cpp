#include <iostream>

using namespace std;

int main(){
    int q[8][8] = {};
    int count = 1, c = 0, r = 0;

    q[0][0] = 1; //set queen 

nc: c++;    //next column
    if (c == 8) goto print;
    r = -1; //reset row

nr: r++;

    if (r == 8) goto backtrack;

    for(int i = 0;  i < c; i++){ //check entire row based on colunm position
        if( q[r][i] == 1 ) goto nr;
    }

    for(int i = 1; (r-i) >= 0 && (c-i) >= 0; i++ ) { //up diaglnal
       if(q[r-i][c-i] == 1) goto nr;
    }

    for(int i = 1; (r+i) < 8 && (c-i) >= 0; i++){ //down diaglnal
        if(q[r+i][c-i] == 1) goto nr;
    }

    q[r][c] = 1;
    goto nc;

backtrack: c--;

    if(c < 0) return 0;
    
    for(int i = 0; i < 8; i++){
        if(q[i][c] == 1){
            r = i;
            q[i][c] = 0;
            break;
        }
    }
    goto nr;

print:
    cout << "Solution: # " << count++ << endl;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    goto backtrack;

}
