# Contributing Guidelines

## [style]

### Function names and prototypes

  Function names shall describe the function purpose.  They shall be all lower case with words
  separated by underscore.  All functions that are not inline shall have prototypes.  Function
  prototypes shall follow the example below:
  
        int name_of_function(int parameter1, int parameter2 = 0);
    
  In function definitions braces shall start one space after the closing parenthases for the
  function parameters and end on the line following the last line of code in the function.
  Function definitions shall follow the example below:
  
        int Name_of_class::name_of_member_function(int parameter1, int parameter2 = 0) {
            return parameter2 + parameter1;
        }
   
### Variable/object names

  Variable names shall descrive the variables contents.  They shall be all lower case with
  words separated by underscore.  Variable names shall follow the example below:
  
        double description_of_variable;
    
### Line spacing

  There shall be no spaces between lines in a function unless a comment describing the line
  below occupies that space.  There shall be one line space between the end of a function
  and the comment of the function below.  Spaceing should follow the example below:
  
        //receives user name from mainwindow and inserts it in uname
        void Downloader::set_uname(QString input_string) {
            if(is_valid(input_string)) {
                uname = input_string;
            }
        }

        //receives passowrd from mainwindow and inserts it in passwd
        void Downloader::set_passwd(QString input_string) {
            if(is_valid(input_string)) {
                passwd = input_string;
            }
        }
    
### Commenting(minimum requirements)

  All functions shall contain a one line comment above the function describing its purpose and
  any amplifying critical information.
  
  All function prototypes will contain an abreviated comment on the same line as the prototype
  in line with the other functions in the same header.
  
  Class variables will contain a comment on the same line as they are defined in line with the
  other variables in the same header.
  
## [Technical code guidelines]

### Qt Framework vs STL Classes

  Only Qt Framework or derived classes/objects shall be included in this project.  No STL classes 
  shall be used directly in the project unless a Qt analogue or container does not exist.
  
### Access specifiers for data members

  Only class data members that are static const data members for the purpose of being used as a bit
  mask shall be delcared public.  All other data members shall be protected or private and accesors
  or mutators provided as appropriate.
  
### Global variables

  The Qt signals and slots mechanism negates the need for any global variable.  The project shall
  contain no new variables in global scope.  If an exemption is thought to be required for this
  guideline an email to the maintainer regarding the request should accompany the pull request.
  
## [Future guidelines]

  Project guidelines may change abruptly.  Before issuing a pull request, please check this page
  to ensure that your code meets the most current guidelines.
