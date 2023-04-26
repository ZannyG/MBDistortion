/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MBDistortionAudioProcessorEditor::MBDistortionAudioProcessorEditor (MBDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    addAndMakeVisible(gainSlider);

    gainSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
}


MBDistortionAudioProcessorEditor::~MBDistortionAudioProcessorEditor()
{
}

//==============================================================================
void MBDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::black);
    g.setFont (15.0f);

    gainSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    gainSlider.setRange(-20, 20);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

void MBDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getLocalBounds());
}

void MBDistortionAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
       audioProcessor.rawVolume = pow(10, gainSlider.getValue() / 20);
    }
}