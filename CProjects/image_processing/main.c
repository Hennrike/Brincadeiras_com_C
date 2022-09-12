// Nome: Henrique Martins Dutra
// Turma: 4324
#include <stdio.h>
#include <inttypes.h>
#pragma pack(1) // remove o "padding", ou espaçamento, da struct

typedef struct
{
    // File Header
    uint16_t img_t;
    uint32_t size;
    uint16_t res1;
    uint16_t res2;
    uint32_t offset;
    // BitMap Header
    uint32_t header_size;
    uint32_t img_width;
    uint32_t img_height;
    uint16_t img_planes;
    uint16_t bitsppx;
    uint32_t compression_t; // inutilizado, valor 0
    uint32_t img_size;
    uint32_t xresolution;
    uint32_t yresolution;
    uint32_t ncolors; // inutilizado, valor 0
    uint32_t importantcolors; // inutilizado, valor 0
}BMP_header;

typedef struct{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
}BGRvalues;

int c, flag=0;
FILE *fp;
FILE *fptemp;

void filtro_RGB(BMP_header fileheader, int opt, int imgsize, char filen[100]){
    BGRvalues BGR;
    fp = fopen(filen, "rb");
    switch(opt){
        case 0: // vermelho
        fptemp = fopen("red.bmp", "ab");
        fwrite(&fileheader, sizeof(fileheader), 1, fptemp);
        fseek(fp, 40, SEEK_SET);
        while(fread(&BGR, sizeof(BGR), 1, fp)!=imgsize/3){
            BGR.red = 255;
            fwrite(&BGR, sizeof(BGR), 1, fptemp);
            flag++;
            if(flag == imgsize/3){
                flag = 0;
                break;
            }
        }
        case 1: // verde
        fptemp = fopen("green.bmp", "ab");
        fwrite(&fileheader, sizeof(fileheader), 1, fptemp);
        fseek(fp, 40, SEEK_SET);
        while(fread(&BGR, sizeof(BGR), 1, fp)!=imgsize/3){
            BGR.green = 255;
            fwrite(&BGR, sizeof(BGR), 1, fptemp);
            flag++;
            if(flag == imgsize/3){
                flag = 0;
                break;
            }
        }
        case 2: // azul
        fptemp = fopen("blue.bmp", "ab");
        fwrite(&fileheader, sizeof(fileheader), 1, fptemp);
        fseek(fp, 40, SEEK_SET);
        while(fread(&BGR, sizeof(BGR), 1, fp)!=imgsize/3){
            BGR.blue = 255;
            fwrite(&BGR, sizeof(BGR), 1, fptemp);
            flag++;
            if(flag == imgsize/3){
                flag = 0;
                break;
            }
        }
    }
    fclose(fptemp);
    fclose(fp);
}

int main(){
    printf("Verificando tamanho do header (precisa ter 54 bytes): %i\n", sizeof(BMP_header));
    BMP_header header;

    fp = fopen("image.bmp", "rb");
    fread(&header, sizeof(BMP_header), 1, fp);
    fclose(fp);
    printf("Exibindo metadados do arquivo:\n\n");
    printf("Tipo de arquivo (424D se for BMP): %x\n", header.img_t);
    printf("Tamanho do arquivo: %i\n", header.size);
    printf("Offset do Header (em bytes): %i\n", header.offset);
    printf("Tamanho do Header (em bytes): %i\n", header.header_size);
    printf("Altura da imagem (em pixels): %i\n", header.img_width);
    printf("Largura da imagem (em pixels): %i\n", header.img_height);
    printf("Bits por Pixel (24 significa TrueColor): %i\n", header.bitsppx);
    printf("Tamanho da imagem (em bytes): %i\n", header.img_size);
    filtro_RGB(header, 0, header.img_size, "image.bmp");
    filtro_RGB(header, 1, header.img_size, "image.bmp");
    filtro_RGB(header, 2, header.img_size, "image.bmp");
}