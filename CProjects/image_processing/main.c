// Nome: Henrique Martins Dutra
// Turma: 4324
#include <stdio.h>
#include <inttypes.h>
#pragma pack(1); // remove o "padding", ou espaçamento, da struct

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

int c;
FILE *fp;
FILE *fptemp;

void filtro_RGB(BMP_header fileheader, int opt, int imgsize, char filen[100]){
    // "data" contém os valores das cores em formato BGR
    unsigned char data[imgsize]; // "unsigned char" foi escolhido por possuir tamanho 256
    fp = fopen(filen, "rb");
    // Lendo cada byte que compõe a imagem
    fread(&data, sizeof(unsigned char), imgsize, fp);
    fclose(fp);

    switch(opt){
        case 0: // vermelho
        for (c=2;c<imgsize;c+=3){
            data[c] = 255;
        }
        fp = fopen("red.bmp", "ab");
        break;

        case 1: // verde
        for (c=1;c<imgsize;c+=3){
            data[c] = 255;
        }
        fp = fopen("green.bmp", "ab");
        break;

        case 2: // azul
        for (c=0;c<imgsize;c+=3){
            data[c] = 255;
        }
        fp = fopen("blue.bmp", "ab");
        break;
    }
    fwrite(&fileheader, sizeof(fileheader), 1, fp);
    fwrite(&data, sizeof(unsigned char), imgsize, fp);
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