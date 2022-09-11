// Nome: Henrique Martins Dutra
// Matrícula: 20000238
// Turma: 4324

#include <stdio.h>
#pragma pack(1)

typedef struct
{
    // RIFF
    int chunkID;
    int chunkSize;
    int format;
    // Format
    int subChunk1ID;
    int subChunk1Size;
    short int audioFormat;
    short int numChannels;
    int sampleRate;
    int byteRate;
    short int blockAlign;
    short int bitsPerSample;
    //Unknown
    short int x;
    // Fact
    int subChunk3ID;
    int subChunk3Size;
    int FDD;
    // Data
    int subChunk2ID;
    int subChunk2Size;
}wavFormat;

int c;
FILE *fp;
FILE *fptemp;
short int sample;

void printInfo(wavFormat wavFile){
    printf("ChuckID: %x\n", wavFile.chunkID);
    printf("ChunkSize: %i\n", wavFile.chunkSize);
    printf("Format: %x\n", wavFile.format);
    printf("SubChunk1ID: %x\n", wavFile.subChunk1ID);
    printf("SubChunk1Size: %i\n", wavFile.subChunk1Size);
    printf("AudioFormat: %i\n", wavFile.audioFormat);
    printf("NumChannels: %i\n", wavFile.numChannels);
    printf("SampleRate: %i\n", wavFile.sampleRate);
    printf("ByteRate: %i\n", wavFile.byteRate);
    printf("BlockAlign: %i\n", wavFile.blockAlign);
    printf("BitsPerSample: %i\n", wavFile.bitsPerSample);
    printf("Subchunk2ID: %x\n", wavFile.subChunk2ID);
    printf("Subchunk2Size: %i\n", wavFile.subChunk2Size);

}

void cortaTrecho(char *nfile, int tInicial, int tFinal){
    wavFormat wavFile;
    wavFormat tempWavFile;
    fp = fopen(nfile, "rb");
    fread(&wavFile, sizeof(wavFormat), 1, fp);
    fclose(fp);
    printInfo(wavFile);


    fp = fopen(nfile, "rb");
    fptemp = fopen("edited.wav", "wb");
    fread(&tempWavFile, sizeof(wavFormat), 1, fp);
    fwrite(&tempWavFile, sizeof(wavFormat), 1, fptemp);
    fclose(fptemp);

    fseek(fp, wavFile.byteRate*tInicial, SEEK_SET);
    fptemp = fopen("edited.wav", "ab");
    while(c<wavFile.byteRate*(tFinal-tInicial)){
            fread(&sample, 1, 1, fp);
            fwrite(&sample, 1, 1, fptemp);
            c++;
    }
    fclose(fptemp);
    fclose(fp);
}

int main(void)
{
    cortaTrecho("youseebiggirl.wav", 258, 368); // nome do arquivo, inicio, fim
}