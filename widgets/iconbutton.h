#ifndef WIDGETS_ICONBUTTON_H
#define WIDGETS_ICONBUTTON_H

#include "../global.h"

#include <QAbstractButton>
#include <QAction>
#include <QPixmap>
#include <QSize>

#include <cstdint>

namespace QtUtilities {

class QT_UTILITIES_EXPORT IconButton : public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap)

public:
    explicit IconButton(QWidget *parent = nullptr);
    ~IconButton() override;

    static IconButton *fromAction(QAction *action, std::uintptr_t id = 0);
    const QPixmap &pixmap() const;
    void setPixmap(const QPixmap &pixmap);
    QSize sizeHint() const override;

    static constexpr auto defaultPixmapSize = QSize(16, 16);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private Q_SLOTS:
    void assignDataFromActionChangedSignal();
    void assignDataFromAction(const QAction *action);

private:
    QPixmap m_pixmap;
};

/*!
 * \brief Returns the pixmap.
 */
inline const QPixmap &IconButton::pixmap() const
{
    return m_pixmap;
}

/*!
 * \brief Sets the pixmap.
 */
inline void IconButton::setPixmap(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
    update();
}
} // namespace QtUtilities

#endif // WIDGETS_ICONBUTTON_H
