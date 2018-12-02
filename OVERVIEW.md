# The Mosaic Project <!-- omit in toc -->

## Authors <!-- omit in toc -->

- Alex
- Cody
- Brady

## Table of Contents <!-- omit in toc -->

- [Project Goals](#project-goals)
  - [Out of scope](#out-of-scope)
- [Design Overview](#design-overview)
- [Implementation Approach](#implementation-approach)
- [Project Outcomes](#project-outcomes)
- [Examples](#examples)

## Project Goals

- Be able to create a grey-scale image out of a series of images based on the intensities of each pixel.
- Ensure that the program runs smoothly with as minimal bugs as possible.

### Out of scope

- Be able to create an RGB image out of a series of images based on the intensities of each pixel.

## Design Overview

For our design, we decided to take a modular approach. We split up the program into 3 components:

- Pre-processing
  - Perform any processing procedures on the images and series of images before building the mosaic.
- Tree of Images
  - To improve performance, the series of images are loading into a binary search tree. This is especially useful when there isn't an exact match of intensity in the tree and we'd like the closest matching intensity.
- Make Mosaic
  - The building of the mosaic image using the BST of the series of images.

## Implementation Approach

Since there were 3 people working on this project, dividing the work was easy enough:

- Alex worked on pre-processing.
- Brady worked on the tree of images.
- Cody worked on making the mosaic.

We all worked on unit tests for our own respective components.

## Project Outcomes

Our program takes in an image as input, and creates a mosaic image using 2800+ images of emojis.

## Examples

Before:
![Before_Image](https://cdn.discordapp.com/attachments/509833085861363738/517484476708945920/test.jpg)

After:
![After_Image](https://cdn.discordapp.com/attachments/509833085861363738/517484514847490054/output.jpg)
