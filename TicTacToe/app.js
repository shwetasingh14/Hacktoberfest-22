var player = '';
var move = 1
var xs = '<i class="fa-regular fa-x"></i>'
var os = '<i class="fa-solid fa-o"></i>'

$('h1').click(function () { location.reload(); });

$('table tr td').click(function () {

    if (winner() === false) {
        if (move % 2 == 1) $(this).html(xs).off('click');
        else $(this).html(os).off('click');

        (move == 9) ? $('h1').text('Play Again') : move++;
        if (winner() === true) $('h1').text('Play Again');
    }
}
)

function winner() {
    var b11 = $('table tr:nth-child(1) td:nth-child(1)').html()
    var b12 = $('table tr:nth-child(1) td:nth-child(2)').html()
    var b13 = $('table tr:nth-child(1) td:nth-child(3)').html()
    var b21 = $('table tr:nth-child(2) td:nth-child(1)').html()
    var b22 = $('table tr:nth-child(2) td:nth-child(2)').html()
    var b23 = $('table tr:nth-child(2) td:nth-child(3)').html()
    var b31 = $('table tr:nth-child(3) td:nth-child(1)').html()
    var b32 = $('table tr:nth-child(3) td:nth-child(2)').html()
    var b33 = $('table tr:nth-child(3) td:nth-child(3)').html()

    if (move % 2 == 0) player = '.p1 h2';
    else player = '.p2 h2';

    //row-wise
    if (b11 == b12 && b12 == b13 && b11 != '') {
        $(player).html('Winner');
        return true;
    }
    else if (b21 == b22 && b22 == b23 && b21 != '') {
        $(player).html('Winner');
        return true;
    }
    else if (b31 == b32 && b32 == b33 && b31 != '') {
        $(player).html('Winner');
        return true;
    }

    //column-wise
    else if (b11 == b21 && b21 == b31 && b11 != '') {
        $(player).html('Winner');
        return true;
    }
    else if (b12 == b22 && b22 == b32 && b12 != '') {
        $(player).html('Winner');
        return true;
    }
    else if (b13 == b23 && b23 == b33 && b13 != '') {
        $(player).html('Winner');
        return true;
    }

    //diagonal-wise
    else if (b11 == b22 && b22 == b33 && b11 != '') {
        $(player).html('Winner');
        return true;
    }
    else if (b13 == b22 && b22 == b31 && b13 != '') {
        $(player).html('Winner');
        return true;
    }

    else
        return false;
}
