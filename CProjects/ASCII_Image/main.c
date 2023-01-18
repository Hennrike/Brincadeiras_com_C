#include <stdio.h>
#pragma pack(1)

typedef struct
{
    // File Header
    short int img_t;
    int size;
    short int res1;
    short int res2;
    int offset;
    // BitMap Header
    int header_size;
    int img_width;
    int img_height;
    short int img_planes;
    short int bitsppx;
    int compression_t; // inutilizado, valor 0
    int img_size;
    int xresolution;
    int yresolution;
    int ncolors; // inutilizado, valor 0
    int importantcolors; // inutilizado, valor 0
}BMP_header;
BMP_header header;

typedef struct{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
}BGRvalues;
BGRvalues BGR;

FILE *fp;
FILE *fptemp;

void bwFilter(BMP_header fileheader, int imgsize, char filen[100]){
    int avg;

    fp = fopen(filen, "rb");
    fptemp = fopen("BW.bmp", "ab");
    
    fwrite(&fileheader, sizeof(fileheader), 1, fptemp);
    fseek(fp, sizeof(fileheader), SEEK_SET);

    for(int c=0;c<fileheader.img_size/3;c++){
        fread(&BGR, sizeof(BGR), 1, fp);
        avg = (BGR.red + BGR.green + BGR.blue) / 3;
        BGR.red = avg;
        BGR.green = avg;
        BGR.blue = avg;
        fwrite(&BGR, sizeof(BGR), 1, fptemp);
    }
    fclose(fptemp);
    fclose(fp);
}

void asciiImage(){
    char brghchars[10] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int brightness;

    fp = fopen("image.bmp", "rb");
    fptemp = fopen("ASCII.txt", "ab");
    
    fseek(fp, sizeof(header), SEEK_SET);
    for(int c=0;c<header.img_size/3;c++){
        fread(&BGR, sizeof(BGR), 1, fp);
        switch(brightness = BGR.red){
            case 0:
                putc(brghchars[0], fptemp);
                break;
            case 25:
                putc(brghchars[1], fptemp);
                break;
            case 50:
                putc(brghchars[2], fptemp);
                break;
            case 75:
                putc(brghchars[3], fptemp);
                break;
            case 100:
                putc(brghchars[4], fptemp);
                break;
            case 125:
                putc(brghchars[5], fptemp);
                break;
            case 150:
                putc(brghchars[6], fptemp);
                break;
            case 175:
                putc(brghchars[7], fptemp);
                break;
            case 200:
                putc(brghchars[8], fptemp);
                break;
            case 250:
                putc(brghchars[9], fptemp);
                break;
        }
        if(c % header.img_width == 0){
            putc('\n', fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
}

int main(){
    fp = fopen("image.bmp", "rb");
    fread(&header, sizeof(BMP_header), 1, fp);
    fclose(fp);

    printf("Exibindo metadados do arquivo:\n\n");
    printf("Tipo de arquivo (424D se for BMP): %x\n", header.img_t);
    printf("Tamanho do arquivo: %i bytes\n", header.size);
    printf("Offset do Header: %i bytes\n", header.offset);
    printf("Tamanho do Header: %i bytes\n", header.header_size);
    printf("Altura da imagem: %i pixels\n", header.img_width);
    printf("Largura da imagem: %i pixels\n", header.img_height);
    printf("Bits por Pixel (24 significa TrueColor): %i bytes\n", header.bitsppx);
    printf("Tamanho da imagem: %i bytes\n", header.img_size);
    asciiImage();
}