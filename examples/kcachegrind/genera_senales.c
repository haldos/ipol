#include "genera_senales.h"

void step(sample_t *signal,int length,int t_up,sample_t amp){
    int index;
    sample_t *psample = signal;
    for(index=0;index<length;index++){
        if (index<t_up){
            *psample = 0;
        } else {
            *psample = amp;
        }
        psample++;
    }
}

void impulse(sample_t *signal,int length){
    sample_t *psample = signal;
    *psample = 1;
    psample++;
    int index;
    for(index=1;index<length;index++){
        *psample = 0;
        psample++;
    }
}
