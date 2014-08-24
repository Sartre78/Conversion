/**
 * 08/24/2014  
 *
 * conversions.c
 *
 * uses "conversions.h" header file.
 *
 * This program, when prompted by the user, will make basic unit conversions
 * for temperature, pressure, distance(length), area, volume, velocity, and 
 * acceleration.  The program operates using a primary switch case, with each
 * metric to be converted having their own switch operators.
 *
 */


// Basic C libraries
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// local header library
#include "conversions.h"

// switch operator "pages"
int temperature (void);
int pressure (void);
int distance (void);
int area (void);
int volume (void);
int velocity (void);
int acceleration (void);


// global variables
float fahrenheit; // degrees fahrenheit
float cel; // degrees celcius
float kel; // degrees kelvin
float rank; // degrees rankine
float psi; // pounds per square inch
float mpa; // mega pascals
float h2o; // inches of water column
float hg; // inches of mercury
float ft; // feet
float m; // meter
float mile; // mile
float kilo; // kilometer
float sqft; // square feet
float sqm; // square meter
float cubft; // cubic feet
float cubm; // cubic meter
float fts; // feet per second
float ms; // meter per second
float mph; // miles per hour
float fts2; // feet per second squared
float ms2; // meters per second squared

// main screen menu option
int main (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK CONVERSION CALCULATORS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Quit\n\n");
        printf("1 - Temperature Conversion\n");
        printf("2 - Pressure Conversion\n");
        printf("3 - Distance-Length Conversion\n");
        printf("4 - Area Conversion\n");
        printf("5 - Volume Conversion\n");
        printf("6 - Velocity Conversion\n");
        printf("7 - Acceleration Conversion\n");
        printf("\n"); 
        int option = GetInt(); // get user's decision
        
        switch (option)
        {
             case 0: printf("\n\nGoodbye!\n\n"); return 0;
             case 1: temperature(); break;
             case 2: pressure(); break;
             case 3: distance(); break;
             case 4: area(); break;
             case 5: volume(); break;
             case 6: velocity(); break;
             case 7: acceleration(); break;
             
             default: printf("\nNot a valid option.\n\n"); break; // invalid option
        }
    }
}

// temperature page
int temperature (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK TEMPERATURE CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - Fahrenheit to Celcius\n");
        printf("2 - Fahrenheit to Rankine\n");
        printf("3 - Fahrenheit to Kelvin\n");
        printf("4 - Celcius to Fahrenheit\n");
        printf("5 - Celcius to Kelvin\n");
        printf("6 - Celcius to Rankine\n");
        printf("7 - Kelvin to Celcius\n");
        printf("8 - Kelvin to Fahrenheit\n");
        printf("9 - Kelvin to Rankine\n");
        printf("10 - Rankine to Fahrenheit\n");
        printf("11 - Rankine to Celcius\n");
        printf("12 - Rankine to Kelvin\n");
        
        printf("\n");
        int temp = GetInt();
        
        switch (temp)
        {
            case 0: return false;
            // F -> C
            case 1: printf("\nPlease enter the temperature in degrees Fahrenheit:\n\n");
                    fahrenheit = GetFloat();
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Celcius.\n\n", fahrenheit, celcius(fahrenheit)); break;
                    
            // F -> R
            case 2: printf("\nPlease enter the temperature in degrees Fahrenheit:\n\n");
                    fahrenheit = GetFloat();
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Rankine.\n\n", fahrenheit, fahrenheit + 459.67); break;
                    
            // F -> K
            case 3: printf("\nPlease enter the temperature in degrees Fahrenheit:\n\n");
                    fahrenheit = GetFloat();
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Kelvin.\n\n", fahrenheit, celcius(fahrenheit) + 273.15); break;
                    
            // C -> F
            case 4: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Fahrenheit.\n\n", cel, fahr(cel)); break;
                    
            // C -> K        
            case 5: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Kelvin.\n\n", cel, cel + 273.15); break;
                    
            // C -> R
            case 6: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Rankine.\n\n", cel, fahr(cel) + 459.67); break;
                    
            // K -> C
            case 7: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Celcius.\n\n", kel, kel - 273.15); break;
            // K -> F
            case 8: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Fahrenheit.\n\n", kel, fahr(kel - 273.15)); break;
                    
            // K -> R
            case 9: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Rankine.\n\n", kel, fahr(kel - 273.15) + 459.67); break;
                            
            // R -> F        
            case 10: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                    rank = GetFloat();
                    printf("\n%.2f Degrees Rankine is %.2f Degrees Fahrenheit.\n\n", rank, rank - 459.67); break;
            // R -> C        
            case 11: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                    rank = GetFloat();
                    printf("\n%.2f Degrees Rankine is %.2f Degrees Celcius.\n\n", rank, celcius(rank - 459.67)); break;
            // R -> K         
            case 12: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                    rank = GetFloat();
                    printf("\n%.2f Degrees Rankine is %.2f Degrees Kelvin.\n\n", rank, celcius(rank - 459.67) + 273.15); break;
                    
            default: printf("\nNot a valid option.\n\n"); break;
        }
    }
}

// pressure page
int pressure (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK PRESSURE CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - PSI to MPa\n");
        printf("2 - PSI to Inches H2O\n");
        printf("3 - PSI to Inches Hg\n");
        printf("4 - MPa to PSI\n");
        printf("5 - MPa to Inches H2O\n");
        printf("6 - MPa to Inches Hg\n");
        printf("7 - Inches H2O to Inches Hg\n");
        printf("8 - Inches H20 to PSI\n");
        printf("9 - Inches H20 to MPa\n");
        printf("10 - Inches Hg to Inches H20\n");
        printf("11 - Inches Hg to PSI\n");
        printf("12 - Inches Hg to MPa\n");        
        printf("\n");
        int pres = GetInt();
        
        switch (pres)
        {
            case 0: return false;
            // PSI -> Mpa
            case 1: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("\n%.2f psi is %.2f Mpa.\n\n", psi, psi_to_mpa(psi)); break;
                    
            // PSI -> H2O
            case 2: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("\n%.2f psi is %.2f inches of water.\n\n", psi, psi_to_h2o(psi)); break;
                    
            // PSI -> Hg
            case 3: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("\n%.2f psi is %.2f inches of Hg.\n\n", psi, h2o_to_hg(psi_to_h2o(psi))); break;
                    
            // MPa -> PSI
            case 4: printf("\nPlease enter the pressure in Mpa:\n\n");
                    mpa = GetFloat();
                    printf("\n%.2f MPa is %.2f psi.\n\n", mpa, mpa_to_psi(mpa)); break;
                    
            // MPa -> H2O        
            case 5: printf("\nPlease enter the pressure in Mpa:\n\n");
                    mpa = GetFloat();
                    printf("\n%.2f MPa is %.2f inches of water.\n\n", mpa, psi_to_h2o(mpa_to_psi(mpa))); break;
                    
            // MPa -> Hg
            case 6: printf("\nPlease enter the pressure in Mpa:\n\n");
                    mpa = GetFloat();
                    printf("\n%.2f Mpa is %.2f inches of Hg.\n\n", mpa, h2o_to_hg(psi_to_h2o(mpa_to_psi(mpa)))); break;          
                    
            // H2O -> Hg
            case 7: printf("\nPlease enter the pressure in inches of water:\n\n");
                    h2o = GetFloat();
                    printf("\n%.2f inches of water is %.2f inches of Hg.\n\n", h2o, h2o_to_hg(h2o)); break;
            // H2O -> PSI
            case 8: printf("\nPlease enter the pressure in inches of water:\n\n");
                    h2o = GetFloat();
                    printf("\n%.2f inches of water is %.2f psi.\n\n", h2o, h2o_to_psi(h2o)); break;
                    
            // H2O -> MPa
            case 9: printf("\nPlease enter the pressure in inches of water:\n\n");
                    h2o = GetFloat();
                    printf("\n%.2f inches of water is %.2f MPa.\n\n", h2o, psi_to_mpa(h2o_to_psi(h2o))); break;           
                            
            // Hg -> H2O        
            case 10: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("\n%.2f inches of Hg is %.2f inches of water.\n\n", hg, hg_to_h2o(hg)); break;
            // Hg -> PSI        
            case 11: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("\n%.2f inches of Hg is %.2f psi.\n\n", hg, h2o_to_psi(hg_to_h2o(hg))); break;
            // Hg -> MPa         
            case 12: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("\n%.2f inches of Hg is %.2f MPa.\n\n", hg, psi_to_mpa(h2o_to_psi(hg_to_h2o(hg)))); break;
                    
            default: printf("\nNot a valid option.\n\n"); break;
        }
    }
}

// distance - length page
int distance (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK DISTANCE-LENGTH CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - feet to meter\n");
        printf("2 - meter to feet\n");
        printf("3 - miles to kilometers\n");
        printf("4 - kilometers to miles\n"); 
        printf("\n");
        int dist = GetInt();
        
        switch (dist)
        {
            case 0: return false;
            // ft -> m
            case 1: printf("\nPlease enter the length in feet:\n\n");
                    ft = GetFloat();
                    printf("\n%.2f feet is %.2f meters.\n\n", ft, ft_to_m(ft)); break;
                    
            // m -> ft
            case 2: printf("\nPlease enter the length in meters:\n\n");
                    m = GetFloat();
                    printf("\n%.2f meters is %.2f feet.\n\n", m, m_to_ft(m)); break;
                    
            // mile -> kilo
            case 3: printf("\nPlease enter the length in miles:\n\n");
                    mile = GetFloat();
                    printf("\n%.2f miles is %.2f kilometers.\n\n", mile, mile_to_kilo(mile)); break;
                    
            // kilo -> mile
            case 4: printf("\nPlease enter the length in kilometers:\n\n");
                    kilo = GetFloat();
                    printf("\n%.2f kilometers is %.2f miles.\n\n", kilo, kilo_to_mile(kilo)); break;
                    
            default: printf("\nNot a valid option.\n\n"); break;   
        }
    }
}

// area page
int area (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK AREA CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - square feet to square meter\n");
        printf("2 - square meter to square feet\n");
        printf("\n");
        int area = GetInt();
        
        switch (area)
        {
            case 0: return false;
            // sqft -> sqm
            case 1: printf("\nPlease enter the area in square feet:\n\n");
                    sqft = GetFloat();
                    printf("\n%.2f square feet is %.2f square meters.\n\n", sqft, sqft_to_sqm(sqft)); break;
                    
            // sqm -> sqft
            case 2: printf("\nPlease enter the area in square meters:\n\n");
                    sqm = GetFloat();
                    printf("\n%.2f square meters is %.2f square feet.\n\n", sqm, sqm_to_sqft(sqm)); break;

            default: printf("\nNot a valid option.\n\n"); break;   
        }
    }
}

// volume page
int volume (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK VOLUME CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - cubic feet to cubic meter\n");
        printf("2 - cubic meter to cubic feet\n");
        printf("\n");
        int vol = GetInt();
        
        switch (vol)
        {
            case 0: return false;
            // ft^3 -> m^3
            case 1: printf("\nPlease enter the volume in cubic feet:\n\n");
                    cubft = GetFloat();
                    printf("\n%.2f cubic feet is %.2f cubic meters.\n\n", cubft, cubft_to_cubm(cubft)); break;
                    
            // m^3 -> ft^3
            case 2: printf("\nPlease enter the volume in cubic meters:\n\n");
                    cubm = GetFloat();
                    printf("\n%.2f cubic meters is %.2f cubic feet.\n\n", cubm, cubm_to_cubft(cubm)); break;

            default: printf("\nNot a valid option.\n\n"); break;   
        }
    }
}

// velocity page
int velocity (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK VELOCITY CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - ft/s to m/s\n");
        printf("2 - ft/s to mph\n");
        printf("3 - m/s to ft/s\n");
        printf("4 - m/s to mph\n");
        printf("5 - mph to ft/s\n");
        printf("6 - mph to m/s\n");     
        printf("\n");
        int vel = GetInt();
        
        switch (vel)
        {
            case 0: return false;
            // ft/s -> m/s
            case 1: printf("\nPlease enter the velocity in feet per second:\n\n");
                    fts = GetFloat();
                    printf("\n%.2f ft/s is %.2f m/s.\n\n", fts, ft_to_m(fts)); break;
                    
            // ft/s -> mph
            case 2: printf("\nPlease enter the velocity in feet per second:\n\n");
                    fts = GetFloat();
                    printf("\n%.2f ft/s is %.2f mph.\n\n", fts, fts_to_mph(fts)); break;
                    
            // m/s -> ft/s
            case 3: printf("\nPlease enter the velocity in meters per second:\n\n");
                    ms = GetFloat();
                    printf("\n%.2f m/s is %.2f f/s.\n\n", ms, m_to_ft(ms)); break;
                    
            // m/s -> mph
            case 4: printf("\nPlease enter the velocity in meters per second:\n\n");
                    ms = GetFloat();
                    printf("\n%.2f m/s is %.2f mph.\n\n", ms, fts_to_mph(m_to_ft(ms))); break;
                    
            // mph -> ft/s
            case 5: printf("\nPlease enter the velocity in miles per hour:\n\n");
                    mph = GetFloat();
                    printf("\n%.2f mph is %.2f ft/s.\n\n", mph, mph_to_fts(mph)); break;
                    
            // mph -> m/s
            case 6: printf("\nPlease enter the velocity in miles per hour:\n\n");
                    mph = GetFloat();
                    printf("\n%.2f mph is %.2f m/s.\n\n", mph, ft_to_m(mph_to_fts(mph))); break;
                    
            default: printf("\nNot a valid option.\n\n"); break;   
        }        
    }
}

// acceleration page
int acceleration (void)
{
    while (true)
    {
        printf("\n\n\n----- QUICK ACCELERATION CONVERSIONS -----\n\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - ft/sec^2 to m/s^2\n");
        printf("2 - m/s^2 to ft/sec^2\n");
        printf("\n");
        int accel = GetInt();
        
        switch (accel)
        {
            case 0: return false;
            // ft/sec^2 -> m/s^2
            case 1: printf("\nPlease enter the acceleration in feet per second squared:\n\n");
                    fts2 = GetFloat();
                    printf("\n%.2f ft/sec^2 is %.2f m/s^2.\n\n", fts2, fts2_to_ms2(fts2)); break;
                    
            // m/s^2 -> ft/sec^2 
            case 2: printf("\nPlease enter the acceleration in meters per second squared:\n\n");
                    ms2 = GetFloat();
                    printf("\n%.2f m/s^2 is %.2f ft/sec^2.\n\n", ms2, ms2_to_fts2(ms2)); break;

            default: printf("\nNot a valid option.\n\n"); break;   
        }
    }
}

