LZWBinFa::LZWBinFa (const LZWBinFa & forras){
std::cout << "Copy ctor" << std::endl;
gyoker = new Csomopont('/');
gyoker->ujEgyesGyermek(masol(forras.gyoker->egyesGyermek(), forras.fa));
gyoker->ujNullasGyermek(masol(forras.gyoker->nullasGyermek(), forras.fa));
if (forras.fa == forras.gyoker){
fa = gyoker;
}
}

Csomopont* LZWBinFa::masol (Csomopont* elem, Csomopont* regi_fa){
Csomopont* ujelem = nullptr;
                
if (elem != nullptr){
ujelem = new Csomopont (elem->getBetu());
                
ujelem -> ujEgyesGyermek(masol(elem->egyesGyermek(), regi_fa));
ujelem -> ujNullasGyermek(masol(elem->nullasGyermek(), regi_fa));
                
if (regi_fa == elem){
fa = ujelem;
}
}
                
return ujelem;

LZWBinFa & LZWBinFa::operator= (const LZWBinFa & forras){                
gyoker->ujEgyesGyermek(masol(forras.gyoker->egyesGyermek(), forras.fa));
gyoker->ujNullasGyermek(masol(forras.gyoker->nullasGyermek(), forras.fa));
                
if (forras.fa == forras.gyoker){
fa = gyoker;
}
return *this;

LZWBinFa::LZWBinFa (LZWBinFa&& forras)
{
gyoker = nullptr;
*this = std::move(forras); 
}

LZWBinFa& LZWBinFa::operator= (LZWBinFa&& forras)
{
std::cout<<"Move assignment ctor\n";
std::swap(gyoker, forras.gyoker);
return *this;
}