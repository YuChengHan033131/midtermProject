#include "function.h"
DA7212 audio;

void playChord(float *notes,int numbers,float time){
    int16_t waveform[kAudioTxBufferSize]={0};
    //synthesis chord wave
    //float sytWave[kAudioTxBufferSize]={0};
    for(int j=0;j<numbers;j++){
        for (int i = 0; i < kAudioTxBufferSize; i++){
            waveform[i] += (int16_t) (sin((double)i * 2. * M_PI / (double) (kAudioSampleFrequency / notes[j]))*0.05* ((1<<16) - 1));
        }
    }
    Timer t;
    t.start();
    while(t.read()<=time){
        audio.spk.play(waveform, kAudioTxBufferSize);
    }
}
void playNote(float freq,float time){
    int16_t waveform[kAudioTxBufferSize]={0};
    for (int i = 0; i < kAudioTxBufferSize; i++){
        waveform[i] += (int16_t) (sin((double)i * 2. * M_PI / (double) (kAudioSampleFrequency / freq))*0.05* ((1<<16) - 1));
    }

    Timer t;
    t.start();
    audio.spk.play();
    while(t.read()<=time){
        audio.spk.play(waveform, kAudioTxBufferSize);
    }
    audio.spk.pause();
    wait(0.1);
}