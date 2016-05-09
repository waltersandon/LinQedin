#include "data.h"

Data::Data(int g, int m, int a):giorno(g), mese(m), anno(a){
    if(consistenza(*this)==false){
            *this=Data();
        }

}

Data::Data(const Data & d):giorno(d.giorno), mese(d.mese), anno(d.anno){}

bool Data::consistenza(const Data & d){
    bool ok=false;
    //per prima cosa controllo che la Data possa consistente
        if(d.giorno<1 || d.giorno >31 || d.mese>12 || d.mese<1)
            return ok;

        //adesso sposto l'attenzione su Febbraio che è un mese critico
        if(d.mese==2 ){
            //per essere bisestile mod400==0 ma mod100!=0 -> mod4==0 e mod400==0
            if( d.anno % 400 == 0 || (d.anno % 100 != 0 && d.anno % 4 == 0)){ //anno bisestile
                if(d.giorno<=29)
                    ok=true;
            }else {
                if(d.giorno<=28)
                    ok=true;
            }
        }else{
            //i mesi 4,6,9,11 hanno 30 gg
            if(d.mese==4 || d.mese==6 || d.mese==9 || d.mese==11){
                if(d.giorno <=30)
                    ok=true;
            }
            //mi mancano i restanti mesi ma per effetto dei controlli precedenti
            //so che sono in un bound corretto
            else ok=true;
        }
        return ok;
}

bool Data::consistenza(const int& g, const int& m, const int& a){
    return consistenza(Data(g,m,a));
}

int Data::visualizza_giorno()const{return giorno;}
int Data::visualizza_mese()const{return mese;}
int Data::visualizza_anno()const{return anno;}

bool Data::modifica_data(const Data & d){
    if (consistenza(d)){
            anno=d.anno;
            mese=d.mese;
            giorno=d.giorno;
            return true;
        }
        return false;
}

Data& Data::operator =(const Data& d){
    anno=d.anno;
    mese=d.mese;
    giorno=d.giorno;
    return *this;
}

void Data::modifica_anno(int a){
    anno=a;
}

void Data::modifica_mese(int m){
    mese=m;
}

void Data::modifica_giorno(int g){
    giorno=g;
}


bool Data::operator==(const Data& d)const{
    return d.anno==anno && d.mese==mese && d.giorno==giorno;
}

bool Data::operator!=(const Data& d)const{return !(d==*this);}
bool Data::operator<(const Data& d)const{
    return anno<=d.anno && mese<=d.mese && giorno<d.giorno;
}
bool Data::operator <=(const Data& d)const{
    return d==*this || d<*this;
}
bool Data::operator >(const Data& d)const{return !(*this<d);}
bool Data::operator >=(const Data& d)const{return *this>d || *this==d;}

string Data::toString() const{
    std::stringstream s;
    s << giorno << '.'<< mese << '.'<< anno;
    return s.str();

}
