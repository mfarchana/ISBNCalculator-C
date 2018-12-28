#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *number3;
static GtkWidget *result;
static GtkWidget *result2;
static GtkWidget *result3;

void do_calculate(GtkWidget *calculate, gpointer data) {
    char text[10];
    strcpy(text,gtk_entry_get_text(GTK_ENTRY(number1)));
    int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));
    int panjang = strlen(text);
    int array[10];

    char buffer[100];
    int i;
    int a;

    for(i = 0;text[i] != 0;i++){
        array[i] = text[i] - '0';
    }

    printf("ISBN-10\t : ");
    for(i=0;i<10;i++){
        printf("%d",array[i]);
    }


    puts("");
    int jml = 0;
    int j;
    for(j = 1;j<=10;j++){
        jml += j*array[j-1];
        if(j<=9){
            printf(" %d ,",jml);
        }
        else{
            printf(" %d",jml);
        }
    }

    printf("\nJumlah = %d\n", jml);
    printf("Hasil Modulo %d mod %d = %d",jml,11,jml%11);

    if(jml%11 == 0){
        int sum = 0;
    for(i=1;i<=9;i++){
        sum += i*array[i-1];
    }
    printf("\n\n . : CekDigit : . \n");
    printf("Jumlah = %d\n",sum);
    printf("Hasil Modulo %d mod %d = %d",sum,11,sum%11);

    printf("\n\nMaka cek digitnya = %d",sum%11);
        snprintf(buffer, sizeof(buffer), "\n\nSelamat ISBN VALID!, Cek Digitnya = %d\n\n",sum%11);
    }
    else{
        snprintf(buffer, sizeof(buffer), "\n\nMaaf, ISBN tidak VALID\n");
    }
    gtk_label_set_text(GTK_LABEL(result), buffer);



}

void do_calculate2(GtkWidget *calculate, gpointer data) {
    char text[10];
    strcpy(text,gtk_entry_get_text(GTK_ENTRY(number2)));
    int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));
    int panjang = strlen(text);
    int array[10];
    char buffer[100];
    int i;


    for(i = 0;text[i] != 0;i++){
        array[i] = text[i] - '0';
        printf("%d",array[i]);
    }


    puts("\n");
    int jml = 0;
    int hasil = 0;
    int j;
    for(j=0;j<13;j+=2){
        hasil += (1*array[j]) + (3*array[j+1]);
        if(j<=11){
            printf(" %d ,",hasil);
        }
        else{
            printf(" %d",hasil);
        }

    }
    printf("\n\n . : Validasi : . \n");
    printf("Jumlah = %d\n",hasil);
    printf("Hasil Modulo %d mod %d = %d",hasil,10,hasil%10);

    if(hasil%10 == 0){
        int sum = 0;
        for(i=0;i<12;i+=2){
            sum += (1*array[i]) + (3*array[i+1]);
        }
    printf("\n\n . : CekDigit : . \n");
    printf("Jumlah = %d\n",sum);
    printf("Hasil Modulo %d mod %d = %d",sum,10,sum%10);

    printf("\nCek Digit / Karakter Uji : 10 - %d = %d",sum%10,10-(sum%10));

    printf("\n\nMaka cek digitnya = %d",10-(sum%10));
        snprintf(buffer, sizeof(buffer), "\n\nSelamat ISBN VALID!, Cek Digitnya = %d\n\n",10-(sum%10));
    }
    else{
        snprintf(buffer, sizeof(buffer), "\n\nMaaf, ISBN tidak VALID\n");
    }
    gtk_label_set_text(GTK_LABEL(result2), buffer);



}

void do_calculate3(GtkWidget *calculate, gpointer data){
    char text[10];
    strcpy(text,gtk_entry_get_text(GTK_ENTRY(number3)));
    //int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));
    int panjang = strlen(text);
    int array[10];
    char buffer[100];
    int i;

    for(i = 0;text[i] != 0;i++){
        array[i] = text[i] - '0';
    }


    puts("\n");
    int jumlah1,jumlah2,jmlawal,hasil;

    printf("ISBN-10\t : ");
    for(i=0;i<10;i++){
        printf("%d",array[i]);
    }

    jmlawal = 38;
    printf("\nISBN-13\t : 978-");
    for(i=0;i<10;i+=3){
        if(i<8){
            printf("%d%d%d-",array[i],array[i+1],array[i+2]);
        }
        else{
            printf("X");
        }
    }

    //CekDigit
    jumlah1 = 0;
    jumlah2 = 0;
    for(i=0;i<=8;i++){
        if(i%2==0 || i == 0){
            jumlah1 += (3*array[i]);
        }
        else{
            jumlah2 += (1*array[i]);
        }
    }

    hasil = jumlah1+jumlah2+jmlawal;
    printf("\nJumlah = %d\n",hasil);
    printf("Hasil Modulo %d mod %d = %d",hasil,10,hasil%10);

    printf("\nCek Digit / Karakter Uji : 10 - %d = %d",hasil%10,10-(hasil%10));

    printf("\n\nISBN-13\t : 978-");
    snprintf(buffer, sizeof(buffer), "%d%d%d-%d%d%d-%d%d%d-%d%d%d-%d",9,7,8,
             array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],10-(hasil%10));

    for(i=0;i<10;i+=3){
        if(i<8){
            printf("%d%d%d-",array[i],array[i+1],array[i+2]);
            }
        else{
            printf("%d",10-(hasil%10));
        }
    }


    gtk_label_set_text(GTK_LABEL(result3), buffer);
}

// gcc 007_gtk.c -o 007_gtk `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
int main(int argc, char **argv) {
    GtkWidget *window, *grid, *calculate, *ISBN10, *ISBN13, *calculate2, *watermark, *calculate3,*image;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300,250);
    gtk_window_set_title(GTK_WINDOW(window), "ISBN Calculator");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    gtk_container_set_border_width(GTK_CONTAINER(window),2);

    image = gtk_image_new_from_file("gambar_isbn.png");
    gtk_grid_attach(GTK_GRID(grid),image,0, -1, 1, 1);



    watermark = gtk_label_new("@AanUser");
    gtk_grid_attach(GTK_GRID(grid), watermark, 4, -2, 1, 1);

    watermark = gtk_label_new(" . : ISBN Calculator : . ");
    gtk_grid_attach(GTK_GRID(grid), watermark, 1, 0, 1, 1);

    ISBN10 = gtk_label_new("ISBN-10: ");
    gtk_grid_attach(GTK_GRID(grid), ISBN10, 0, 1, 1, 1);


    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 1, 1, 1, 1);

    ISBN13 = gtk_label_new("ISBN-13: ");
    gtk_grid_attach(GTK_GRID(grid), ISBN13, 0, 2, 1, 1);

    number2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number2, 1, 2, 1, 1);

    calculate2 = gtk_button_new_with_label("calculate");
    g_signal_connect(calculate2, "clicked", G_CALLBACK(do_calculate2), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate2, 3, 2, 1, 1);

    result2 = gtk_label_new("result:");
    gtk_grid_attach(GTK_GRID(grid), result2, 4, 2, 1, 1);


    calculate = gtk_button_new_with_label("calculate");
    g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate, 3, 1, 1, 1);

    result = gtk_label_new("result:");
    gtk_grid_attach(GTK_GRID(grid), result, 4, 1, 1, 1);

    ISBN13 = gtk_label_new("Convert ISBN-10 to ISBN-13: ");
    gtk_grid_attach(GTK_GRID(grid), ISBN13, 1, 3, 1, 1);

    ISBN10 = gtk_label_new("ISBN-10: ");
    gtk_grid_attach(GTK_GRID(grid), ISBN10, 0, 4, 1, 1);

    number3 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number3, 1, 4, 1, 1);

    calculate3 = gtk_button_new_with_label("convert");
    g_signal_connect(calculate3, "clicked", G_CALLBACK(do_calculate3), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate3, 3, 4, 1, 1);

    result3 = gtk_label_new("result:");
    gtk_grid_attach(GTK_GRID(grid), result3, 4, 4, 1, 1);


    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
