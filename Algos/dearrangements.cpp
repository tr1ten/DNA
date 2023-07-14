const int MAX=5;
ll dearr[MAX+1];
void dearrangements(){
    dearr[0] =1;dearr[1] = 0;
    rep(i,2,MAX+1){
        dearr[i] = (i-1)*(dearr[i-1]+dearr[i-2]);
    }

}