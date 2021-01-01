/**
 *  @file constants.hpp
 *  @brief All constant variables 
 *  @ingroup EyeTracking 
 *  @author Ari Nguyen
 */
#pragma once

// Eyes' Size Constants
const int cEyePercentTop = 25;
const int cEyePercentSide = 13;
const int cEyePercentHeight = 30;
const int cEyePercentWidth = 35;

// Face Constants
const bool cFaceSmoothImage = false;
const float cFaceSmoothFactor = 0.005;

// Algorithm Parameters
const int cEyeFastWidth = 50;
const int cWeightBlurSize = 5;
const bool cEnableWeight = true;
const float cWeightDivisor = 1.0;
const double cGradientThreshold = 50.0;

// Post processing
const bool cEnablePostProcess = true;
const float cPostProcessThreshold = 0.97;

// Eye Corner
const bool cEnableEyeCorner = false;
