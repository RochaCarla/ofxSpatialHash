//
// Copyright (c) 2013 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofMain.h"
#include "ofxSpatialHash.h"


class ofApp: public ofBaseApp
{
public:
    typedef glm::vec2 Vec2;
    typedef glm::vec3 Vec3;
//    typedef ofVec2f Vec2;
//    typedef ofVec3f Vec3;

    ofApp();
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    /// \brief A collection of default values.
    enum
    {
        NUM_POINTS = 20000,
        DEFAULT_RADIUS = 200, // vector units (pixels)
        DEFAULT_NEAREST_N = 200
    };

    /// \brief Our point collection.
    ///
    /// These points MUST be initialized BEFORE initing the hash.
    std::vector<Vec2> points;

    /// \brief The spatial hash specialized for glm::vec2.
    ofx::KDTree<Vec2> hash;

    /// \brief The search results specialized for glm::vec2.
    ofx::KDTree<Vec2>::SearchResults searchResults;

    /// \brief The current mouse position.
    Vec2 mouse;

    /// \brief A mesh to make it easier to draw lots of points.
    ofMesh mesh;

    /// \brief The search modes in this example.
    enum Modes
    {
        MODE_RADIUS,
        MODE_NEAREST_N
    };

    /// \brief The current search mode.
    int mode = 0;

    /// \brief Radius used for radius search.
    int radius = 0;

    /// \brief Number of nearest neighbors to use for Nearest Nieghbor search.
    int nearestN = 0;

};
