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
float pas; // pascals
float h2o; // inches of water column
float hg; // inches of mercury
float mmh2o; // millimeters of water column
float mmhg; // millimeters of mercury
float ft; // feet
float m; // meter
float mile; // mile
float kilo; // kilometer
float in; // inch
float cm; // centimeter
float mm; // millimeter
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
                    // Absolute limit condition
                    while (fahrenheit < -459.67) 
                    {
                        printf("\nThe lowest possible temperature is -459.67 degrees Fahrenheit.  Please retry:\n\n");
                        fahrenheit = GetFloat();
                    }
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Celcius.\n\n", fahrenheit, celcius(fahrenheit)); break;
                    
            // F -> R
            case 2: printf("\nPlease enter the temperature in degrees Fahrenheit:\n\n");
                    fahrenheit = GetFloat();
                    // Absolute limit condition
                    while (fahrenheit < -459.67) 
                    {
                        printf("\nThe lowest possible temperature is -459.67 degrees Fahrenheit.  Please retry:\n\n");
                        fahrenheit = GetFloat();
                    }
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Rankine.\n\n", fahrenheit, fahrenheit + 459.67); break;
                    
            // F -> K
            case 3: printf("\nPlease enter the temperature in degrees Fahrenheit:\n\n");
                    fahrenheit = GetFloat();
                    // Absolute limit condition
                    while (fahrenheit < -459.67) 
                    {
                        printf("\nThe lowest possible temperature is -459.67 degrees Fahrenheit.  Please retry:\n\n");
                        fahrenheit = GetFloat();
                    }
                    printf("\n%.2f Degrees Fahrenheit is %.2f Degrees Kelvin.\n\n", fahrenheit, celcius(fahrenheit) + 273.15); break;
                    
            // C -> F
            case 4: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    // Absolute limit condition
                    while (cel < -273.15) 
                    {
                        printf("\nThe lowest possible temperature is -273.15 degrees Celcius.  Please retry:\n\n");
                        cel = GetFloat();
                    }
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Fahrenheit.\n\n", cel, fahr(cel)); break;
                    
            // C -> K        
            case 5: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    // Absolute limit condition
                    while (cel < -273.15) 
                    {
                        printf("\nThe lowest possible temperature is -273.15 degrees Celcius.  Please retry:\n\n");
                        cel = GetFloat();
                    }
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Kelvin.\n\n", cel, cel + 273.15); break;
                    
            // C -> R
            case 6: printf("\nPlease enter the temperature in degrees Celcius:\n\n");
                    cel = GetFloat();
                    // Absolute limit condition
                    while (cel < -273.15) 
                    {
                        printf("\nThe lowest possible temperature is -273.15 degrees Celcius.  Please retry:\n\n");
                        cel = GetFloat();
                    }
                    printf("\n%.2f Degrees Celcius is %.2f Degrees Rankine.\n\n", cel, fahr(cel) + 459.67); break;
                    
            // K -> C
            case 7: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    // Absolute limit condition
                    while (kel < 0) 
                    {
                        printf("\nThe lowest possible temperature is 0 degrees Kelvin.  Please retry:\n\n");
                        kel = GetFloat();
                    }
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Celcius.\n\n", kel, kel - 273.15); break;
                    
            // K -> F
            case 8: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    // Absolute limit condition
                    while (kel < 0) 
                    {
                        printf("\nThe lowest possible temperature is 0 degrees Kelvin.  Please retry:\n\n");
                        kel = GetFloat();
                    }
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Fahrenheit.\n\n", kel, fahr(kel - 273.15)); break;
                    
            // K -> R
            case 9: printf("\nPlease enter the temperature in degrees Kelvin:\n\n");
                    kel = GetFloat();
                    // Absolute limit condition
                    while (kel < 0) 
                    {
                        printf("\nThe lowest possible temperature is 0 degrees Kelvin.  Please retry:\n\n");
                        kel = GetFloat();
                    }
                    printf("\n%.2f Degrees Kelvin is %.2f Degrees Rankine.\n\n", kel, fahr(kel - 273.15) + 459.67); break;
                            
            // R -> F        
            case 10: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                     rank = GetFloat();
                     // Absolute limit condition
                     while (rank < 0) 
                     {
                        printf("\nThe lowest possible temperature is 0 degrees Rankine.  Please retry:\n\n");
                        rank = GetFloat();
                     }
                     printf("\n%.2f Degrees Rankine is %.2f Degrees Fahrenheit.\n\n", rank, rank - 459.67); break;
                     
            // R -> C        
            case 11: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                     rank = GetFloat();
                     // Absolute limit condition
                     while (rank < 0) 
                     {
                        printf("\nThe lowest possible temperature is 0 degrees Rankine.  Please retry:\n\n");
                        rank = GetFloat();
                     }
                     printf("\n%.2f Degrees Rankine is %.2f Degrees Celcius.\n\n", rank, celcius(rank - 459.67)); break;
                     
            // R -> K         
            case 12: printf("\nPlease enter the temperature in degrees Rankine:\n\n");
                     rank = GetFloat();
                     // Absolute limit condition
                     while (rank < 0) 
                     {
                        printf("\nThe lowest possible temperature is 0 degrees Rankine.  Please retry:\n\n");
                        rank = GetFloat();
                     }
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
        printf("\n----- QUICK PRESSURE CONVERSIONS -----\n\n");
        printf("Please choose an option:\n\n");
        printf("0 - Return to main screen\n\n");
        printf("1 - PSI to Pascals\n");
        printf("2 - PSI to Inches H2O\n");
        printf("3 - PSI to Inches Hg\n");
        printf("4 - PSI to mmH2O\n");
        printf("5 - PSI to mmHg\n");
        printf("6 - Pascals to PSI\n");
        printf("7 - Pascals to Inches H2O\n");
        printf("8 - Pascals to Inches Hg\n");
        printf("9 - Pascals to mmH2O\n");
        printf("10 - Pascals to mmHg\n");
        printf("11 - Inches H2O to Inches Hg\n");
        printf("12 - Inches H2O to PSI\n");
        printf("13 - Inches H2O to Pascals\n");
        printf("14 - Inches H2O to mmH2O\n");
        printf("15 - Inches H2O to mmHg\n");
        printf("16 - Inches Hg to Inches H2O\n");
        printf("17 - Inches Hg to PSI\n");
        printf("18 - Inches Hg to Pascals\n"); 
        printf("19 - Inches Hg to mmH2O\n");
        printf("20 - Inches Hg to mmHg\n");
        printf("21 - mmH2O to mmHg\n");
        printf("22 - mmH2O to Inches H2O\n");
        printf("23 - mmH2O to Inches Hg\n");
        printf("24 - mmH2O to PSI\n");
        printf("25 - mmH2O to Pascals\n");
        printf("26 - mmHg to mmH2O\n");
        printf("27 - mmHg to Inches Hg\n");
        printf("28 - mmHg to Inches H2O\n");
        printf("29 - mmHg to PSI\n");
        printf("30 - mmHg to Pascals\n");       
        printf("\n");
        int pres = GetInt();
        
        switch (pres)
        {
            case 0: return false;
            
            // PSI -> pascals
            case 1: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("%.3f psi is %.3f pascals.\n", psi, psi_to_pas(psi)); break;
                    
            // PSI -> in H2O
            case 2: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("%.3f psi is %.3f inches of water.\n", psi, psi_to_h2o(psi)); break;
                    
            // PSI -> in Hg
            case 3: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("%.3f psi is %.3f inches of Hg.\n", psi, h2o_to_hg(psi_to_h2o(psi))); break;
                    
            // PSI -> mm H2O
            case 4: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("%.3f psi is %.3f millimeters of water.\n", psi, in_to_mm(psi_to_h2o(psi))); break;
            
            // PSI -> mm Hg
            case 5: printf("\nPlease enter the pressure in psi:\n\n");
                    psi = GetFloat();
                    printf("%.3f psi is %.3f millimeters of Hg.\n", psi, in_to_mm(h2o_to_hg(psi_to_h2o(psi)))); break;
                    
            // Pascals -> PSI
            case 6: printf("\nPlease enter the pressure in pascals:\n\n");
                    pas = GetFloat();
                    printf("%.3f Pascals is %.3f psi.\n", pas, pas_to_psi(pas)); break;
                    
            // Pascals -> in H2O        
            case 7: printf("\nPlease enter the pressure in pascals:\n\n");
                    pas = GetFloat();
                    printf("%.3f Pascals is %.3f inches of water.\n", pas, psi_to_h2o(pas_to_psi(pas))); break;
                    
            // Pascals -> in Hg
            case 8: printf("\nPlease enter the pressure in pascals:\n\n");
                    pas = GetFloat();
                    printf("%.3f Pascals is %.3f inches of Hg.\n", pas, h2o_to_hg(psi_to_h2o(pas_to_psi(pas)))); break;          
            
            // Pascals -> mm H2O
            case 9: printf("\nPlease enter the pressure in pascals:\n\n");
                    pas = GetFloat();
                    printf("%.3f Pascals is %.3f millimeters of water.\n", pas, in_to_mm(psi_to_h2o(pas_to_psi(pas)))); break;
          
            // Pascals -> mm Hg
            case 10: printf("\nPlease enter the pressure in pascals:\n\n");
                     pas = GetFloat();
                     printf("%.3f Pascals is %.3f millimeters of Hg.\n", pas, in_to_mm(h2o_to_hg(psi_to_h2o(pas_to_psi(pas))))); break;
                    
            // in H2O -> in Hg
            case 11: printf("\nPlease enter the pressure in inches of water:\n\n");
                     h2o = GetFloat();
                     printf("%.3f inches of water is %.3f inches of Hg.\n", h2o, h2o_to_hg(h2o)); break;
                     
            // in H2O -> PSI
            case 12: printf("\nPlease enter the pressure in inches of water:\n\n");
                     h2o = GetFloat();
                     printf("%.3f inches of water is %.3f psi.\n", h2o, h2o_to_psi(h2o)); break;
                    
            // in H2O -> Pascals
            case 13: printf("\nPlease enter the pressure in inches of water:\n\n");
                     h2o = GetFloat();
                     printf("%.3f inches of water is %.3f Pascals.\n", h2o, psi_to_pas(h2o_to_psi(h2o))); break;           
            
            // in H2O -> mm H2O
            case 14: printf("\nPlease enter the pressure in inches of water:\n\n");
                     h2o = GetFloat();
                     printf("%.3f inches of water is %.3f millimeters of water.\n", h2o, in_to_mm(h2o)); break;
            
            // in H2O -> mm Hg
            case 15: printf("\nPlease enter the pressure in inches of water:\n\n");
                     h2o = GetFloat();
                     printf("%.3f inches of water is %.3f millimeters of Hg.\n", h2o, in_to_mm(h2o_to_hg(h2o))); break;  
                          
            // in Hg -> in H2O        
            case 16: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("%.3f inches of Hg is %.3f inches of water.\n", hg, hg_to_h2o(hg)); break;
                     
            // in Hg -> PSI        
            case 17: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("%.3f inches of Hg is %.3f psi.\n", hg, h2o_to_psi(hg_to_h2o(hg))); break;
                     
            // in Hg -> Pascals         
            case 18: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("%.3f inches of Hg is %.3f Pascals.\n", hg, psi_to_pas(h2o_to_psi(hg_to_h2o(hg)))); break;
            
            // in Hg -> mm H2O
            case 19: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("%.3f inches of Hg is %.3f millimeters of water.\n", hg, mmhg_to_mmh2o(in_to_mm(hg))); break;
            
            // in Hg -> mm Hg
            case 20: printf("\nPlease enter the pressure in inches of Hg:\n\n");
                     hg = GetFloat();
                     printf("%.3f inches of Hg is %.3f millimeters of Hg.\n", hg, in_to_mm(hg)); break;
            
            // mm H2O -> mm Hg
            case 21: printf("\nPlease enter the pressure in millimeters of water:\n\n");
                     mmh2o = GetFloat();
                     printf("%.3f millimeters of water is %.3f millimeters of Hg.\n", mmh2o, mmh2o_to_mmhg(mmh2o)); break;
            
            // mm H2O -> in H2O
            case 22: printf("\nPlease enter the pressure in millimeters of water:\n\n");
                     mmh2o = GetFloat();
                     printf("%.3f millimeters of water is %.3f inches of water.\n", mmh2o, mm_to_in(mmh2o)); break;
            
            // mm H2O -> in Hg
            case 23: printf("\nPlease enter the pressure in millimeters of water:\n\n");
                     mmh2o = GetFloat();
                     printf("%.3f millimeters of water is %.3f inches of Hg.\n", mmh2o, mm_to_in(mmh2o_to_mmhg(mmh2o))); break;
            
            // mm H2O -> PSI
            case 24: printf("\nPlease enter the pressure in millimeters of water:\n\n");
                     mmh2o = GetFloat();
                     printf("%.3f millimeters of water is %.3f psi.\n", mmh2o, h2o_to_psi((mm_to_in(mmh2o)))); break;
            
            // mm H2O -> Pascals
            case 25: printf("\nPlease enter the pressure in millimeters of water:\n\n");
                     mmh2o = GetFloat();
                     printf("%.3f millimeters of water is %.3f Pascals.\n", mmh2o, psi_to_pas(h2o_to_psi(mm_to_in(mmh2o)))); break;
            
            // mm Hg -> mm H2O
            case 26: printf("\nPlease enter the pressure in millimeters of Hg:\n\n");
                     mmhg = GetFloat();
                     printf("%.3f millimeters of Hg is %.3f millimeters of water.\n", mmhg, mmhg_to_mmh2o(mmhg)); break;
            
            // mm Hg -> in Hg
            case 27: printf("\nPlease enter the pressure in millimeters of Hg:\n\n");
                     mmhg = GetFloat();
                     printf("%.3f millimeters of Hg is %.3f inches of Hg.\n", mmhg, mm_to_in(mmhg)); break;
            
            // mm Hg -> in H2O
            case 28: printf("\nPlease enter the pressure in millimeters of Hg:\n\n");
                     mmhg = GetFloat();
                     printf("%.3f millimeters of Hg is %.3f inches of water.\n", mmhg, hg_to_h2o(mm_to_in(mmhg))); break;
            
            // mm Hg -> PSI
            case 29: printf("\nPlease enter the pressure in millimeters of Hg:\n\n");
                     mmhg = GetFloat();
                     printf("%.3f millimeters of Hg is %.3f psi.\n", mmhg, h2o_to_psi(hg_to_h2o(mm_to_in(mmhg)))); break;
            
            // mm Hg -> Pascals
            case 30: printf("\nPlease enter the pressure in millimeters of Hg:\n\n");
                     mmhg = GetFloat();
                     printf("%.3f millimeters of Hg is %.3f Pascals.\n", mmhg, psi_to_pas(h2o_to_psi(hg_to_h2o(mm_to_in(mmhg))))); break;
            
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
        printf("5 - inches to millimeters\n");
        printf("6 - inches to centimeters\n");
        printf("7 - centimeters to inches\n");
        printf("8 - centimeters to millimeters\n");
        printf("9 - millimeters to inches\n");
        printf("10 - millimeters to centimeters\n");
        printf("\n");
        int dist = GetInt();
        
        switch (dist)
        {
            case 0: return false;
            
            // ft -> m
            case 1: printf("\nPlease enter the length in feet:\n\n");
                    ft = GetFloat();
                    // Absolute limit condition
                    while (ft < 0) {printf("\nPlease enter a value greater than zero:\n\n"); ft = GetFloat();}
                    printf("\n%.2f feet is %.2f meters.\n\n", ft, ft_to_m(ft)); break;
                    
            // m -> ft
            case 2: printf("\nPlease enter the length in meters:\n\n");
                    m = GetFloat();
                    // Absolute limit condition
                    while (m < 0) {printf("\nPlease enter a value greater than zero:\n\n"); m = GetFloat();}
                    printf("\n%.2f meters is %.2f feet.\n\n", m, m_to_ft(m)); break;
                    
            // mile -> kilo
            case 3: printf("\nPlease enter the length in miles:\n\n");
                    mile = GetFloat();
                    // Absolute limit condition
                    while (mile < 0) {printf("\nPlease enter a value greater than zero:\n\n"); mile = GetFloat();}
                    printf("\n%.2f miles is %.2f kilometers.\n\n", mile, mile_to_kilo(mile)); break;
                    
            // kilo -> mile
            case 4: printf("\nPlease enter the length in kilometers:\n\n");
                    kilo = GetFloat();
                    // Absolute limit condition
                    while (kilo < 0) {printf("\nPlease enter a value greater than zero:\n\n"); kilo = GetFloat();}
                    printf("\n%.2f kilometers is %.2f miles.\n\n", kilo, kilo_to_mile(kilo)); break;
                    
            // inch -> millimeter
            case 5: printf("\nPlease enter the length in inches:\n\n");
                    in = GetFloat();
                    // Absolute limit condition
                    while (in < 0) {printf("\nPlease enter a value greater than zero:\n\n"); in = GetFloat();}
                    printf("\n%.2f inches is %.2f millimeters.\n\n", in, in_to_mm(in)); break;        
            
            // inch -> centimeter
            case 6: printf("\nPlease enter the length in inches:\n\n");
                    in = GetFloat();
                    // Absolute limit condition
                    while (in < 0) {printf("\nPlease enter a value greater than zero:\n\n"); in = GetFloat();}
                    printf("\n%.2f inches is %.2f centimeters.\n\n", in, in_to_mm(in) / 10.0); break;  
            
            // centimeters -> inch
            case 7: printf("\nPlease enter the length in centimeters:\n\n");
                    cm = GetFloat();
                    // Absolute limit condition
                    while (cm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); cm = GetFloat();}
                    printf("\n%.2f centimeters is %.2f inches.\n\n", cm, mm_to_in(cm * 10.0)); break;  
            
            // centimeters -> millimeters
            case 8: printf("\nPlease enter the length in centimeters:\n\n");
                    cm = GetFloat();
                    // Absolute limit condition
                    while (cm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); cm = GetFloat();}
                    printf("\n%.2f centimeters is %.2f millimeters.\n\n", cm, cm * 10.0); break; 
            
            // millimeters -> inch
            case 9: printf("\nPlease enter the length in millimeters:\n\n");
                    mm = GetFloat();
                    // Absolute limit condition
                    while (mm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); mm = GetFloat();}
                    printf("\n%.2f millimeters is %.2f inches.\n\n", mm, mm_to_in(mm)); break;
            
            // millimeters -> centimeters
            case 10: printf("\nPlease enter the length in millimeters:\n\n");
                     mm = GetFloat();
                     // Absolute limit condition
                     while (mm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); mm = GetFloat();}
                     printf("\n%.2f millimeters is %.2f centimeters.\n\n", mm, mm / 10.0); break;
                    
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
                    // Absolute limit condition
                    while (sqft < 0) {printf("\nPlease enter a value greater than zero:\n\n"); sqft = GetFloat();}
                    printf("\n%.2f square feet is %.2f square meters.\n\n", sqft, sqft_to_sqm(sqft)); break;
                    
            // sqm -> sqft
            case 2: printf("\nPlease enter the area in square meters:\n\n");
                    sqm = GetFloat();
                    // Absolute limit condition
                    while (sqm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); sqm = GetFloat();}
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
                    // Absolute limit condition
                    while (cubft < 0) {printf("\nPlease enter a value greater than zero:\n\n"); cubft = GetFloat();}
                    printf("\n%.2f cubic feet is %.2f cubic meters.\n\n", cubft, cubft_to_cubm(cubft)); break;
                    
            // m^3 -> ft^3
            case 2: printf("\nPlease enter the volume in cubic meters:\n\n");
                    cubm = GetFloat();
                    // Absolute limit condition
                    while (cubm < 0) {printf("\nPlease enter a value greater than zero:\n\n"); cubm = GetFloat();}
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
                    // Absolute limit condition
                    while (fts < 0) {printf("\nPlease enter a value greater than zero:\n\n"); fts = GetFloat();}
                    printf("\n%.2f ft/s is %.2f m/s.\n\n", fts, ft_to_m(fts)); break;
                    
            // ft/s -> mph
            case 2: printf("\nPlease enter the velocity in feet per second:\n\n");
                    fts = GetFloat();
                    // Absolute limit condition
                    while (fts < 0) {printf("\nPlease enter a value greater than zero:\n\n"); fts = GetFloat();}
                    printf("\n%.2f ft/s is %.2f mph.\n\n", fts, fts_to_mph(fts)); break;
                    
            // m/s -> ft/s
            case 3: printf("\nPlease enter the velocity in meters per second:\n\n");
                    ms = GetFloat();
                    // Absolute limit condition
                    while (ms < 0) {printf("\nPlease enter a value greater than zero:\n\n"); ms = GetFloat();}
                    printf("\n%.2f m/s is %.2f f/s.\n\n", ms, m_to_ft(ms)); break;
                    
            // m/s -> mph
            case 4: printf("\nPlease enter the velocity in meters per second:\n\n");
                    ms = GetFloat();
                    // Absolute limit condition
                    while (ms < 0) {printf("\nPlease enter a value greater than zero:\n\n"); ms = GetFloat();}
                    printf("\n%.2f m/s is %.2f mph.\n\n", ms, fts_to_mph(m_to_ft(ms))); break;
                    
            // mph -> ft/s
            case 5: printf("\nPlease enter the velocity in miles per hour:\n\n");
                    mph = GetFloat();
                    // Absolute limit condition
                    while (mph < 0) {printf("\nPlease enter a value greater than zero:\n\n"); mph = GetFloat();}
                    printf("\n%.2f mph is %.2f ft/s.\n\n", mph, mph_to_fts(mph)); break;
                    
            // mph -> m/s
            case 6: printf("\nPlease enter the velocity in miles per hour:\n\n");
                    mph = GetFloat();
                    // Absolute limit condition
                    while (mph < 0) {printf("\nPlease enter a value greater than zero:\n\n"); mph = GetFloat();}
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
                    // Absolute limit condition
                    while (fts2 < 0) {printf("\nPlease enter a value greater than zero:\n\n"); fts2 = GetFloat();}
                    printf("\n%.2f ft/sec^2 is %.2f m/s^2.\n\n", fts2, fts2_to_ms2(fts2)); break;
                    
            // m/s^2 -> ft/sec^2 
            case 2: printf("\nPlease enter the acceleration in meters per second squared:\n\n");
                    ms2 = GetFloat();
                    // Absolute limit condition
                    while (ms2 < 0) {printf("\nPlease enter a value greater than zero:\n\n"); ms2 = GetFloat();}
                    printf("\n%.2f m/s^2 is %.2f ft/sec^2.\n\n", ms2, ms2_to_fts2(ms2)); break;

            default: printf("\nNot a valid option.\n\n"); break;   
        }
    }
}

