#include<iostream>
using namespace std;
class Creature
{
protected:
    int m_nlifeValue,m_nPower;
public:
    virtual void Attack(Creature *pCreature){}
    virtual void Hurted(int nPower){}
    virtual void FightBack(Creature *pCreature){}
};
class Dragon:public Creature
{
private:
    /* data */
public:
    virtual void Attack(Creature *pCreature);
    virtual void Hurted(int nPower);
    virtual void FightBack(Creature *pCreature);
};
void Dragon::Attack(Creature *p){
    p->Hurted(m_nPower);
    p->FightBack(this);
}
void Dragon::Hurted(int nPower){
    m_nlifeValue-=nPower;
}
void Dragon::FightBack(Creature *p){
    p->Hurted(m_nPower/2);
}
int main(){

}