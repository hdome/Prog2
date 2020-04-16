/*
 BHAX 391 adás - Lab4.: Matrix design init hack, COVID19 - Corona Em. Brdc. - Stay Home
 https://www.twitch.tv/videos/588138046
 https://youtu.be/oLErhmTA2Z0
 
 BHAX 407 adás - Lab5.: Matrix design/2 init hack, COVID19 - Corona Em. Brdc. - Stay Home
 
 */


#include "z3a18qa5_from_scratch.h"

#include <fstream>
#include <iomanip>
#include <filesystem>

class COVID19Var {

    private:
        std::string loc;
        std::string date;
        std::string id;        
        ZLWTree<char, '/', '0'> zlwBt;        

    public:
        COVID19Var(std::string id, std::string loc, std::string date):id(id), loc(loc), date(date)
        {
            std::ifstream ifs{std::string("genomes/")+id+loc+date};
            std::istreambuf_iterator<char> isbiEnd;

            
            for(std::istreambuf_iterator<char> isbi{ifs}; isbi != isbiEnd; ++isbi)
                zlwBt << *isbi;
        
            zlwBt.eval();                  
        }    
        
        void print() {zlwBt.print();}
        
        bool operator<(const COVID19Var & other) const { return zlwBt < other.zlwBt;}
        
        double getMean() const {return zlwBt.getMean();}
        double getVar() const {return zlwBt.getVar();}        
        std::string getName() const {return id+std::string(" ")+loc+std::string(" ")+date;}        
        
};

int main()
{

    std::string path{"genomes"};
    
    for(const auto & entry1: std::filesystem::directory_iterator(path))
    {
        
        for(const auto & entry2: std::filesystem::directory_iterator(path))
        {
                        
            ZLWTree<char, '/', '0'> zlwBt;        

            std::ifstream ifs1{entry1.path().string()};
            std::istreambuf_iterator<char> isbi1End;

            std::ifstream ifs2{entry2.path().string()};
            std::istreambuf_iterator<char> isbi2End;
            
            for(std::istreambuf_iterator<char> isbi1{ifs1}, isbi2{ifs2}; 
                isbi1 != isbi1End || isbi2 != isbi2End; 
                )
                {

                    if(isbi1 != isbi1End)
                    {
                        zlwBt << *isbi1;
                        ++isbi1;
                    }
                    if(isbi2 != isbi2End)
                    {
                        zlwBt << *isbi2;
                        ++isbi2;
                    }
                    
                }
                
            zlwBt.eval();            
            std::cout << std::setw(8) << zlwBt.getVar();            
            
        }
        
        std::cout << std::endl;            
    }        
        











    
}
