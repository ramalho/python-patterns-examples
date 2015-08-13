

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

/* A Simple ProgressBar for test execution display
 */

class ProgressBar
{
public:
                ProgressBar     (CWnd *baseWindow, CRect& bounds);

    void        step            (bool successful);
    void        paint           (CDC& dc);
    int         scale           (int value);
    void        reset           ();
    void        start           (int total);

protected:

    void        paintBackground (CDC& dc);
    void        paintStatus     (CDC& dc);
    COLORREF    getStatusColor  ();
    void        paintStep       (int startX, int endX);

    CWnd        *m_baseWindow;
    CRect       m_bounds;

    bool        m_error;
    int         m_total;
    int         m_progress;
    int         m_progressX;
};



// Construct a ProgressBar
inline ProgressBar::ProgressBar (CWnd *baseWindow, CRect& bounds)
: m_baseWindow (baseWindow), m_bounds (bounds), m_error (false), 
m_total (0), m_progress (0), m_progressX (0)
{}


// Get the current color
inline COLORREF ProgressBar::getStatusColor ()
{ return m_error ? RGB (255, 0, 0) : RGB (0, 255, 0); }



#endif