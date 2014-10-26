replace_field
=============

Replace a string inside a separator

**********************
	field_substitution(int argc, char* argv[]) :  \
  	position( (int) argv[1][0] - '0'),            \
	separator(argv[2]), ReplaceWith(argv[3]),     \
	path(argv[4]){}                                                           // costructor
	field_substitution() {}                                                   // costructor
  	~field_substitution() {}                                                  // destructor
  
	int field_pos(int f_p){position = f_p; return position;};                 // Add Position of field, starting with 0 to Max
	string field_sep(string f_s){separator = f_s; return separator;};         // Add separator, where the string is delimited 
	string field_replace(string f_r){ReplaceWith = f_r; return ReplaceWith;}; // The field will be replaced with this string
	string field_path(string f_p){path = f_p; return path;};                  // Add the pathfile, you file will not mofified

	void field_go();                                                          // Replace the field, delimited with separator, 
	                                                                          // with my string, will be created a new file 
	                                                                          // with extension <filename>_replaced.txt

********************************************************************

Example of executed:
  Input:
    replace_field.exe 1 i ciao C:\\Users\\Utente\\Desktop\\proof.txt
  
  the proof.txt is: Marco|Rocci|Italy
  
  Output:
    Marco|ciao|Italy
    
