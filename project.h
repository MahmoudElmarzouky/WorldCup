using namespace std;
#include"var3.h" 
class team : public  var3
{
	public :
		static int x;
	    void print_message() const;
		void delete_club();
		void update_club();
		void display_club();
		void search_club();
		void insert_club();
		team teams();
		friend void control();
};
