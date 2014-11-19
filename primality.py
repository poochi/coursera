#!/usr/bin/env python

#############GCD METHOD######################



################RABIN MILLER BEGINS ################
def factorize(value):
    p = value&(~(value-1))
    return [p,value/p];

def exponent(base,exp,modulo):
    s =1;
    while exp:        
        if exp&1 == 1:
            s*=base;
        base*=base;
        base%=modulo;
        exp/=2;
    return s;

        
def fermattest(base,maxexponent,modulo):
    t=1;
    while t<=maxexponent:
        t*=2;
        base*=base
        base%=modulo;
        if base == 1 or base == modulo-1:
            return True;
    return False

def rabin_miller(val):
    A_LIST = [2,3,7,9,11,83,5]
    for each in A_LIST:
        if val<=each:
            return True;
        [p,r] = factorize(val-1);
        base = exponent(each,r,val);
        if base ==1 or base == val-1:
            continue;
        if fermattest(base,p,val):
            continue;
        return False;
    return True;

if __name__ == '__main__':
    import time
    import matplotlib.pyplot as plt
    import matplotlib.path as mpath
    import numpy as np
    

    timelapsed = [];
    isprime = [];
    begin = time.clock();    
    for each in xrange(1000):
        start = time.clock();
        v = rabin_miller(each)
        timelapsed.append((time.clock()-start));
        isprime.append(0.9 if v==True else 0.4);        
    #print zip(timelapsed,isprime);
    isprime = np.where(np.array(isprime) == 0, 0, 1)
    plt.scatter(np.linspace(0,len(timelapsed),len(timelapsed)),np.array(timelapsed) ,c =isprime
        ,edgecolor='none',marker='<')
    plt.show();
    
