#include <iostream>
using namespace std;

class Furniture{
    private:
        string m_material;
    public:
        Furniture(string material) : m_material(material){}
        void DisplayInfo() const{
            cout << "Material: " << m_material << endl;
        }
        string GetMaterial() const{
            return m_material;
        }
};

class Chair: public Furniture{
    private:
        bool m_hasBack;
    public:
        Chair(string material, bool hasBack): Furniture(material), m_hasBack(hasBack){}

        void DisplayInfo() const{
            cout << "Chair Information: " << endl;
            Furniture::DisplayInfo();
            cout << "Has Back: Yes/No" << ((m_hasBack) ? "Yes" : "No") << endl;
        }
};

class Table: public Furniture{
    private:
        int m_seats;
    public:
        Table(string material, int seats): Furniture(material), m_seats(seats){}

        void DisplayInfo() const{
            cout << "Table Information:" << endl;
            Furniture::DisplayInfo();
            cout << "Seats: " << m_seats << " people" << endl;
        }
};

int main(){
    Chair chair("Metal", true);
    Table table("Wood", 4);
    chair.DisplayInfo();
    table.DisplayInfo();
    cout << chair.GetMaterial() << endl;
}