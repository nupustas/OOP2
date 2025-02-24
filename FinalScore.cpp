#include "manolib.h"

void FinalScore(vector<Stud> &grupe)
{

    for(auto &n :grupe){
        sort(n.paz.begin(), n.paz.end());

        int suma=0;
            for(auto n: n.paz)
            {
            suma=suma+n;}
            if(n.vm=='v'){
                n.galutinis= 0.4*(suma/n.paz.size())+0.6*n.egz;
            }
            else if (n.paz.size()%2==0){
                n.galutinis=0.4*(n.paz[n.paz.size()/2] + n.paz[n.paz.size()/2-1])/2 +0.6*n.egz;
            }
            else{
                n.galutinis=0.4*n.paz[n.paz.size()/2] +0.6*n.egz;
            }
        }

}