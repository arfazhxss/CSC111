#include <stdio.h>

void quote();
void framed_quote();
void print_surface_area();

    /*  I arranged the main() function for better readability when printing the file altogether.
     *  Please modify the main() function in any way, in order to grade the assignment.        
     */

int main() {
    printf("\nQUOTE FUNCTION\n\n");
    quote();
    printf("\n\nFRAMED QUOTE FUNCTION\n\n");
    framed_quote();
    printf("\n\nSURFACE AREA FUNCTION\n\n");
    print_surface_area();

    return 0;
}

    /*  Purpose: Printing "I'm not sleeping, I'm inspecting the inside of my eyelids" - Hawkeye Pierce
     *  Parameters: The function does not have any parameters of it's own. */

void quote() {
    printf("\"I'm not sleeping, I'm inspecting the inside of my eyelids\" - Hawkeye Pierce");
}

    /*  Purpose: Printing the above quotation with frame around it.
     *  Parameters: The function does not have any parameters of it's own. */

void framed_quote() {
    printf("/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~******~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\\\n");
    printf("|*\"I’m not sleeping, I’m inspecting the inside of my eyelids\" - Hawkeye Pierce*|\n");
    printf("\\*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~******~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/\n");
}

    /*  Purpose: Printing the surface area of a cylinder, given it's height and diameter.
     *  Parameters: The function does not have any parameters of it's own. */

void print_surface_area() {
    double height = 1.11;
    double diameter = 6.0;
    double pi = 3.1415;
    double circumference = 2*pi*(diameter/2);
    double top_cylinder_area = (pi*(diameter/2)*(diameter/2));
    double cylinder_wall_area = ((height)*(circumference));
    double surface_area = (2*(top_cylinder_area))+(cylinder_wall_area);

    printf("The total surface area is %.2f meters squared\n", surface_area);

}