/**
 * 08/24/2014  
 *
 * conversions.h
 *
 * used with "conversions.c" program file.
 *
 * This program, when prompted by the user, will make basic unit conversions
 * for temperature, pressure, distance(length), area, volume, velocity, and 
 * acceleration.  The program operates using a primary switch case, with each
 * metric to be converted having their own switch operators.
 *
 */

// Fahrenheit to Celcius conversion
float celcius (float x) {return (((x - 32) * 5.0) / 9.0);}

// Celcius to Fahrenheit conversion
float fahr (float x) {return (((x * 9.0) / 5.0) + 32);}

// Pounds per square inch (psi) to mega-pascals
float psi_to_mpa (float x) {return x * 0.00689475728;}

// mega-pascals to psi
float mpa_to_psi (float x) {return x * 145.03773800;} 

// psi to inches of water
float psi_to_h2o (float x) {return x * 27.6799048425;}

// inches of water to psi
float h2o_to_psi (float x) {return x * (1 / 27.6799048425);}

// inches of water to inches of mercury (Hg)
float h2o_to_hg (float x) {return x * 0.07355591246342814;}

// inches hg to inches h2o
float hg_to_h2o (float x) {return x * (1 / 0.07355591246342814);}

// feet to meters
float ft_to_m (float x) {return x * 0.3048;}

// meter to feet
float m_to_ft (float x) {return x * (1 / 0.3048);}

// kilometer to miles
float kilo_to_mile (float x) {return x * 0.6121371;}

// miles to kilometers
float mile_to_kilo (float x) {return x * (1 / 0.6121371);}

// square ft to square meters
float sqft_to_sqm (float x) {return x * 0.09290304;}

// square meters to square feet
float sqm_to_sqft (float x) {return x * (1 / 0.09290304);}

// cubic feet to cubic meters
float cubft_to_cubm (float x) {return x * 0.0283168466;}

// cubic meters to cubic feet
float cubm_to_cubft (float x) {return x * (1 / 0.0283168466);}

// feet per second to miles per hour
float fts_to_mph (float x) {return x * (3600.0 / 5280.0);}

// mph to ft/s
float mph_to_fts (float x) {return x * (5280.0 / 3600.0);}

// ft/sec^2 to m/s^2
float ms2_to_fts2 (float x) {return x * 3.2808399;}

// m/s^2 to ft/sec^2
float fts2_to_ms2 (float x) {return x / 3.2808399;}



